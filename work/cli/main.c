/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#include <stdio.h>
#include <conio.h>
#include "middlware/cli.h"
#include "cli_test.h"

int main()
{
    if ( cli_test_init() == true )
    {
        while (1)
        {
            char ch;
            ch = getch();
            printf("%c",ch);
            if (cli_cmd_process_char(ch) == false)
                return false;
        }
        return false;
    }
}
