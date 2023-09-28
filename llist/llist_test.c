/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "middlware/llist.h"
#include "llist_test.h"
#include <stdio.h>
#include <string.h>

/**********************************/
int llist_main(void)
{
    char* data1 = "\nmy data for node1";
    struct node nd1 = { NULL,NULL,data1 };

    char* data2 = "\nmy data for node2";
    struct node nd2 = { NULL,NULL,data2 };

    char* data3 = "\nmy data for node3";
    struct node nd3 = { NULL,NULL,data3 };

    char* data4 = "\nmy data for node4";
    struct node nd4 = { NULL,NULL,data4 };

    struct llist my_list = { NULL,NULL };


    //================================
    if (llist_node_append(&my_list, &nd1) == false)
        printf("error adding node %s", (char*)nd1.p_data);

    if (llist_node_append(&my_list, &nd2) == false)
        printf("error adding node %s", (char*)nd2.p_data);

    if (llist_node_append(&my_list, &nd3) == false)
        printf("error adding node %s", (char*)nd3.p_data);

    llist_debug_print_llist_all_nodes(&my_list, 
                                      llist_user_node_debug_print_data);

    if (llist_node_insert(&my_list, &nd2, &nd4) == false)
        printf("error adding node %s", (char*)nd4.p_data);

    llist_debug_print_llist_all_nodes(&my_list, 
                                      llist_user_node_debug_print_data);

    llist_node_bubble_sort(&my_list, llist_user_node_compare);
    llist_debug_print_llist_all_nodes(&my_list, 
                                      llist_user_node_debug_print_data);

    return 1;
}

void llist_user_node_debug_print_data(struct node* nd)
{
    printf("%s", (char*)nd->p_data);
}

int llist_user_node_compare(struct node* nd1, struct node* nd2)
{
    int rcv = strcmp((char*)nd1->p_data, (char*)nd2->p_data);
    return(rcv);
}

/**********************************/
