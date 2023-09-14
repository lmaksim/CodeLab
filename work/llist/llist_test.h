/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "middlware/llist.h"

/**********************************/
#define USER_DATA_NODES  	10
#define USER_DATA_NAME_SIZE 35

struct user_data
{
    int id;

};

/**********************************/
/* this function implememets data extraction function according
 * to llist_node_cmp_ft in llist.h typedef */
void user_node_get_data( struct node*, struct user_data* );

/* this function implements compare function according
 * to llist_node_data_ft in llist.h typedef */
char user_node_compare ( struct node*, struct node* );

/* this function prints one node data */
void user_node_debug_print_data ( struct node* );
/**********************************/
