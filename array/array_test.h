/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "middlware/array.h"

/**********************************/
struct user_arr_elm
{
    int data;

} ;

/**********************************/
/* Function implements compare function according
 * to arr_elm_prt_cb typedef in llist.h */
char user_arr_cmp_elm ( unsigned char*, unsigned char* );

/* Function implements switch between 
 * two elements according to arr_elm_switch_cb typedef in llist.h */
void user_arr_switch_elm ( unsigned char*, unsigned char* );

/* Function implements element to element copy according
 * to arr_elm_cpy_cb typedef in llist.h */
void user_arr_cpy_elm_data( unsigned char*, unsigned char* );

/* Function implements printing of  
 * element according to arr_elm_prt_cb typedef in llist.h */
void user_arr_print_elm_data( unsigned char* );

int array_main(void);

/**********************************/
