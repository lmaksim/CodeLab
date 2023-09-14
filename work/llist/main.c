/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include <stdio.h>
#include <string.h>
#include "llist_test.h"

void my_node_print(struct node* nd);

int my_node_cmp(struct node* ,struct node*);

/**********************************/
int main(void)
{
    char *data1 = "\nmy data for node1";
    struct node nd1 = {NULL,NULL,data1};

    char *data2 = "\nmy data for node2";
    struct node nd2 = {NULL,NULL,data2};

    char *data3 = "\nmy data for node3";
    struct node nd3 = {NULL,NULL,data3};

    char *data4 = "\nmy data for node4";
    struct node nd4 = {NULL,NULL,data4};

    struct llist my_list = {NULL,NULL};


    //================================
    if (llist_node_append(&my_list,&nd1) == false)
        printf("error adding node %s", (char*)nd1.p_data);

    if (llist_node_append(&my_list,&nd2) == false)
        printf("error adding node %s", (char*)nd2.p_data);

    if (llist_node_append(&my_list,&nd3) == false)
        printf("error adding node %s", (char*)nd3.p_data);

    llist_debug_print_llist_all_nodes(&my_list, my_node_print);

    if (llist_node_insert(&my_list,&nd2, &nd4) == false)
        printf("error adding node %s", (char*)nd4.p_data);

    llist_debug_print_llist_all_nodes(&my_list, my_node_print);

    llist_node_bubble_sort(&my_list, my_node_cmp);
    llist_debug_print_llist_all_nodes(&my_list, my_node_print);
}

void my_node_print(struct node* nd)
{
    printf("%s", (char*)nd->p_data);
}

int my_node_cmp(struct node* nd1 ,struct node* nd2)
{
   int rcv = strcmp((char *)nd1->p_data, (char *)nd2->p_data);
   return(rcv);
}

