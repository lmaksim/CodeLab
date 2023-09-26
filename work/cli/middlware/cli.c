/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
#include "cli.h"
#include <string.h>

static struct cli_cmd cmd_arr[CLI_CMD_ARRAY] = {NULL};
static char cmd[CLI_CMD_SIZE] = {'\0'};
static int cmd_idx = 0;

int cli_cmd_find_in_array( struct cli_cmd *cmd_arr, char *cmd )
{
    for( int i = 0 ; i < cmd_idx ; i++ )
        if ( strcmp( cmd_arr[i].cmd, cmd ) == 0 )
            return i;
    return -1;
}

bool cli_cmd_sort_array( struct cli_cmd *cmd_arr )
{
    bool flag = true;
    struct cli_cmd cmd_temp = {NULL};

    while (flag == true)
    {
        flag = false;
        for( int i = 0 ; i < cmd_idx-1 ; i++ )
        {
          if ( strcmp( cmd_arr[i].cmd, cmd_arr[i+1].cmd ) > 0 )
          {
              memset( &cmd_temp, 0, sizeof(struct cli_cmd) );
              cmd_temp = cmd_arr[i];
              cmd_arr[i] = cmd_arr[i+1];
              cmd_arr[i+1] = cmd_temp;
              flag = true;
          }
        }
    }
    return false;
}

bool cli_cmd_register_new( struct cli_cmd *cmd_arr_new )
{
    if (cmd_idx < CLI_CMD_ARRAY)
    {
        memset(&cmd_arr[cmd_idx],0,sizeof(struct cli_cmd));
        memcpy(&cmd_arr[cmd_idx],cmd_arr_new,sizeof(struct cli_cmd));
        cmd_idx ++;
        cli_cmd_sort_array( cmd_arr );
        return true;
    }
    else
    {
         printf ("Maximum size exceeded, refer to CLI_CMD_ARRAY value");
         return false;
    }
}

unsigned char cli_cmd_process_tab( struct cli_cmd *cmd_arr, char *cmd )
{
    printf ("\n");
    for( int i = 0 ; i < cmd_idx ; i++ )
        if ( strstr(cmd_arr[i].cmd, cmd) != NULL )
            printf ("%s ",cmd_arr[i].cmd);
    return 1;
}

unsigned char cli_cmd_handle_error( void )
{
    printf( "\nerror: no %s command found\n", cmd );
    return 1;
}

bool cli_cmd_print_all( char* prms )
{
    for( int i = 0 ; i < cmd_idx ; i++ )
    {
        printf( "\n@%s - ", cmd_arr[i].cmd );
        printf( "%s ", cmd_arr[i].desc );
    }
    return true;
}

bool cli_cmd_process_char( char ch )
{
    static unsigned char idx = 0;
    #define CH_TAB 9
    #define CH_ENTER 13

    if (((ch >= 'a') & (ch <= 'z')) ||
        (ch == '-') ||
        ((ch >= '0') & (ch <= '9')))
    {
        cmd[idx] = ch;
        idx++;
        return true;
    }
    else if (ch == CH_TAB)
    {
        cmd[idx] = '\0';
        cli_cmd_process_tab( cmd_arr, cmd );
        return true;
    }
    else if (ch == CH_ENTER)
    {
        cmd[idx] = '\0';
        if ( idx > 0 )
        {
            int i = cli_cmd_find_in_array( cmd_arr, cmd );
            if (i == -1)
                cli_cmd_handle_error();
            else
            {
                char tmp_str[] = "-";
                cmd_arr[i].func_cmd( strstr( cmd, tmp_str ) );
            }
            idx = 0;
            memset( cmd, '\0', sizeof(cmd) );
        }
        printf ("\n");
        return true;
    }
    else if (ch == '\b')
    {
        printf (" ");
        printf ("\b");
        if ( idx > 0 )
            idx --;
        return true;
    }
    else if (ch == 'Q')
        return false;

    cli_cmd_handle_error();
    return true;
};
