#include <stdio.h>
#include <conio.h>

#define max_size 5
int main()
{
    for ( int i = 0 ; i <= max_size ; i ++ )
        printf("cycle done, %d\n", (i%max_size) );

    return 0;
}
