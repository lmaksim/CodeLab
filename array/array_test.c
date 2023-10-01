/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#include "array_test.h"
#include <stdio.h>
#include <conio.h>

/**********************************/


/**********************************/
void user_arr_get_elm_data(int* p_elm)
{
    printf("\n Enter data:");
    scanf_s("%d", p_elm);
}

int user_arr_cmp_elm(unsigned char* p_elmf,
                     unsigned char* p_elms)
{
    if(*p_elmf<*p_elms)
        return -1;
    else if(*p_elmf>*p_elms)
        return 1;
    else
        return 0;
}

void user_arr_switch_elm(unsigned char* p_elmf,
                         unsigned char* p_elms)
{
    char elmt;

    elmt=*p_elmf;
    *p_elmf=*p_elms;
    *p_elms=elmt;
}

void user_arr_cpy_elm_data(unsigned char* p_elmf,
                           unsigned char* p_elms)
{
    *p_elmf=*p_elms;
}

void user_arr_print_elm_data(unsigned char* p_elm)
{
    printf("\n %d ", *p_elm);
}

int array_main( void )
{
    unsigned char array[10] = {1,2,5,8,9,7,3,4,6,5};
    unsigned char elm = 4; 
    unsigned char* p = NULL;
    p = array_linear_search(array, (unsigned char)sizeof(array), 1, &elm, &user_arr_cmp_elm);
    printf("%d", *p);
    return 1;
}
