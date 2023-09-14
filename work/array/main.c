/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
 /**********************************/
#include "array_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXIT_KEY 0
int main( void )
{
    /*char p_arr[] = {7,5,3,6};
    size_t num = sizeof ( p_arr )/sizeof ( char );
    size_t size = sizeof ( char );
    char* p_elm;
    //char elm;

    // code
    printf("\nThe array values are:");
    array_print_all( p_arr, num, size ,user_arr_print_elm_data );

    printf("\nSorted Array is:");
    array_buble_sort( p_arr, num, size, user_arr_cmp_elm, user_arr_switch_elm );
    //array_insertion_sort( p_arr, num, size, user_arr_cmp_elm, user_arr_switch_elm );
    //NA - array_selection_sort( p_arr, num, size, user_arr_cmp_elm, user_arr_switch_elm );
    //NA - array_mearge_sort( p_arr, num, size, user_arr_cmp_elm, user_arr_switch_elm );
    //NA - array_quick_sort( p_arr, num, size, user_arr_cmp_elm, user_arr_switch_elm );
    array_print_all( p_arr, num, size ,user_arr_print_elm_data );

    while(1)
    {
        int ch;
        printf("\nSearch array value:");
        scanf("%d" , &(ch) );
        //elm = (char)ch;
        //p_elm = array_linear_search( p_arr, num , size, &elm, user_arr_cmp_elm );
        //p_elm = array_binary_search( p_arr, num , size, &elm, user_arr_cmp_elm );
        //if ( p_elm != NULL )
        //    printf("The value is found!" );
        //else
        //    printf("\nThe value is not found in array" );
    }*/
}

/*#define SIZE_OF_FIFO 5

int main( void )
{
    char p_fifo[SIZE_OF_FIFO] = {0};
    char ch, idx = 0 ;
    struct fifo fifo = { p_fifo,
               p_fifo,
               e_arrtrue
    };


    printf("\n*********************************");
    printf("\nHello to array component example\n");
    printf("\n\n->Maximum available fifo elements is %d", SIZE_OF_FIFO);

    while (1)
    {
        while ( idx++ < SIZE_OF_FIFO )
        {
            printf("\nenter new element to push:");
            scanf(" %c", &(ch));
            {
                if ( array_fifo_push( p_fifo,
                                      SIZE_OF_FIFO,
                                      sizeof(char),
                                      &fifo,
                                      &ch,
                                      user_arr_cpy_elm_data ) == e_arrtrue)
                    printf("push success" );
                else
                {
                    printf("end of fifo" );
                    break;
                }
            }
        }

        while (--idx)
        {
            if ( array_fifo_pop( p_fifo,
                                 SIZE_OF_FIFO,
                                 sizeof(char),
                                 &fifo,
                                 &ch,
                                 user_arr_cpy_elm_data ) == e_arrtrue )
                printf("\n%c poped", ch );
            else
            {
                printf(" pop error!" );
                break;
            }
        }
    }
}*/

