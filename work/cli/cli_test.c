/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
#include "cli_test.h"
#include "middlware/cli.h"
#include <stdio.h>
#include <conio.h>
//---------------------------------
bool cli_tst1_cb( char *prms )
{
    /*<-h> - print command -h\n"
      <-t> - print command -t\n"
      <-c> - print command -c\n"*/

        //if (prms) printf ("%s",cmd_arr[i].cmd);
     printf("\nin tst1");
     return true;
}

bool cli_tst2_cb( char *prms )
{
    /*<-h> - print command -h\n"
      <-t> - print command -t\n"
      <-c> - print command -c\n"*/

        //if (prms) printf ("%s",cmd_arr[i].cmd);
     printf("\nin tst2");
     return true;
}

bool cli_tst3_cb( char *prms )
{
    /*<-h> - print command -h\n"
      <-t> - print command -t\n"
      <-c> - print command -c\n"*/

        //if (prms) printf ("%s",cmd_arr[i].cmd);
     printf("\nin tst3");
     return true;
}
//=================================
const char cmd_help_text[] = "help";
const char cmd_help_desc[] = "command prints all registered commands"
                             "(no parameters available)";
struct cli_cmd cli_cmd_help = { cmd_help_text, cli_cmd_print_all, cmd_help_desc };

//=================================
const char cmd_tst1_text[] = "tst1";
const char cmd_tst1_desc[] =
        "command used to i... tst1\n"
        "   the parameters are:\n"
        "   <-h> - print command -h\n"
        "   <-t> - print command -t\n"
        "   <-c> - print command -c";

struct cli_cmd cli_cmd_test1 = { cmd_tst1_text, cli_tst1_cb, cmd_tst1_desc  };
//=================================
const char cmd_tst2_text[] = "tst2";
const char cmd_tst2_desc[] =
        "command used to i... tst2\n"
        "   the parameters are:\n"
        "   <-h> - print command -h\n"
        "   <-t> - print command -t\n"
        "   <-c> - print command -c";

struct cli_cmd cli_cmd_test2 = { cmd_tst2_text, cli_tst2_cb, cmd_tst2_desc  };
//=================================
const char cmd_tst3_text[] = "tst3";
const char cmd_tst3_desc[] =
        "command used to i... tst3\n"
        "   the parameters are:\n"
        "   <-h> - print command -h\n"
        "   <-t> - print command -t\n"
        "   <-c> - print command -c";

struct cli_cmd cli_cmd_test3 = { cmd_tst3_text, cli_tst3_cb, cmd_tst3_desc  };
//=================================

bool cli_test_init()
{
    if ( cli_cmd_register_new ( &cli_cmd_help ) == false )
    {
        printf("No option to register new command\n");
        return false;
    }

    if ( cli_cmd_register_new ( &cli_cmd_test1 ) == false )
    {
        printf("No option to register new command\n");
        return false;
    }

    if ( cli_cmd_register_new ( &cli_cmd_test2) == false )
    {
        printf("No option to register new command\n");
        return false;
    }

    if ( cli_cmd_register_new ( &cli_cmd_test3 ) == false )
    {
        printf("No option to register new command\n");
        return false;
    }
    return true;
}

int cli_main()
{
    if (cli_test_init() == true)
    {
        while (1)
        {
            char ch;
            ch = _getch();
            printf("%c", ch);
            if (cli_cmd_process_char(ch) == false)
                return false;
        }
        return false;
    }
    return true;
}
