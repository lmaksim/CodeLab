/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#define USER_DATA_NODES  	10
#define USER_DATA_NAME_SIZE 35

struct user_data
{
    int id;

};

/**********************************/
/* this function implements compare function according
 * to llist_node_data_ft in llist.h typedef */
int llist_user_node_compare ( struct node*, struct node* );

/* this function prints one node data */
void llist_user_node_debug_print_data ( struct node* );

int llist_main(void);

/**********************************/
