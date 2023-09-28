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
/* this function implements compare function according
 * to llist_node_data_ft in llist.h typedef */
char user_arr_cmp_elm ( unsigned char*, unsigned char* );

/* this function implements switch function according
 * to llist_node_data_ft in llist.h typedef */
void user_arr_switch_elm ( unsigned char*, unsigned char* );

/* this function implememets data extraction function according
 * to llist_node_cmp_ft in llist.h typedef */
void user_arr_cpy_elm_data( unsigned char*, unsigned char* );

/* this function implememets data extraction function according
 * to llist_node_cmp_ft in llist.h typedef */
void user_arr_print_elm_data( unsigned char* );

/* !!!!!!!!!n function according
 * to llist_node_cmp_ft in llist.h typedef */
int array_main(void);

/**********************************/
