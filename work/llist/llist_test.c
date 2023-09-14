/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "llist_test.h"
#include <stdio.h>

/**********************************/
void user_node_get_data(struct node* p_node,
                        struct user_data* p_udata)
{
    printf("Enter user data : ID(id):");
    scanf("%d", &p_udata->id);
    p_node->p_data = p_udata;
}

char user_node_compare(struct node* p_nodef,
                       struct node* p_nodes)
{
    char ret = 0;

    if (((struct user_data*)p_nodef->p_data)->id == ((struct user_data*)p_nodes->p_data)->id)
        ret = 0;
    else if (((struct user_data*)p_nodef->p_data)->id > ((struct user_data*)p_nodes->p_data)->id)
        ret = 1;
    else if (((struct user_data*)p_nodef->p_data)->id < ((struct user_data*)p_nodes->p_data)->id)
        ret = -1;

    return ret;
}

void user_node_debug_print_data(struct node* p_node)
{
    printf("\nnode data = %d ", ((struct user_data*)p_node->p_data)->id);
}
/**********************************/
