#include <stdio.h>
#include <stdbool.h>

#define CLI_CMD_ARRAY 256
#define CLI_CMD_SIZE  256

struct cli_cmd {

    // command name
    const char *cmd;
    // command callback function
    bool (*func_cmd)( char *prms );
    // command description
    const char *desc;
};

// register new command
bool cli_cmd_register_new ( struct cli_cmd* );

// used for help command
bool cli_cmd_print_all( char* );

// main function to be called periodically
bool cli_cmd_process_char( char ch );


