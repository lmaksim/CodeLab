/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/*************************************************/
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
/*************************************************/
/* ----------- basic functions -------*/
bool llist_node_append(struct llist* p_ll,
                              struct node* p_node)
{
    bool ret = false;

    // empty link list
    if (p_ll->p_head == NULL)
    {
        p_ll->p_head = p_node;
        p_ll->p_tail = p_node;
        p_ll->p_tail->p_prev = NULL;
        p_ll->p_head->p_next = NULL;
        ret = true;
    }
    // add to the end
    else
    {
        p_ll->p_tail->p_next = p_node;
        p_node->p_prev = p_ll->p_tail;
        p_ll->p_tail = p_node;
        p_ll->p_tail->p_next = NULL;
        ret = true;
    }
    return ret;
}

bool llist_node_remove(struct llist* p_ll,
                       struct node* p_node)
{
    bool ret = false;

    if (p_node != NULL)
    {
        // middle node
        if ((p_node->p_next != NULL) &&
                (p_node->p_prev != NULL))
        {
            p_node->p_prev->p_next = p_node->p_next;
            p_node->p_next->p_prev = p_node->p_prev;
            ret = true;
        }
        // first node
        else if ((p_node->p_prev == NULL) &&
                 (p_node->p_next != NULL))
        {
            p_ll->p_head = p_node->p_next;
            p_node->p_next->p_prev = NULL;
            ret = true;
        }
        // last node
        else if ((p_node->p_prev != NULL) &&
                 (p_node->p_next == NULL))
        {
            p_node->p_prev->p_next = NULL;
            p_ll->p_tail = p_node->p_prev;
            ret = true;
        }
        // only one
        else if ((p_node->p_prev == NULL) &&
                 (p_node->p_next == NULL))
        {
            p_ll->p_head = NULL;
            p_ll->p_tail = NULL;
            ret = true;
        }
    }
    return ret;
}

bool llist_node_insert(struct llist* p_ll,
                       struct node* p_nodeb,
                       struct node* p_node)
{
    bool ret = false;

    // insert before first node
    if (p_nodeb->p_prev == NULL)
    {
        p_nodeb->p_prev = p_node;
        p_node->p_next = p_nodeb;
        p_ll->p_head = p_node;
        ret = true;
    }
    // insert before middle node
    else if (p_nodeb != NULL)
    {
        p_node->p_prev = p_nodeb->p_prev;
        p_nodeb->p_prev->p_next = p_node;

        p_nodeb->p_prev = p_node;
        p_node->p_next = p_nodeb;

        ret = true;
    }
    // else
    else
    {
        ret = false;
    }
    return ret;
}

/* ---------  operation functions -------------*/
bool llist_node_switch(struct llist* p_ll,
                       struct node* p_nodef,
                       struct node* p_nodes)
{

    /* if nodef is first */
    if (p_nodef == p_ll->p_head)
        p_ll->p_head = p_nodes;
    else
        p_nodef->p_prev->p_next = p_nodes;

    /* if nodes is last */
    if (p_nodes == p_ll->p_tail)
        p_ll->p_tail = p_nodef;
    else
        p_nodes->p_next->p_prev = p_nodef;

    /* handle next pointers */
    p_nodef->p_next = p_nodes->p_next;
    p_nodes->p_next = p_nodef;

    /* handle prev pointers */
    p_nodes->p_prev = p_nodef->p_prev;
    p_nodef->p_prev = p_nodes;

    return true;
}

/* ---------  search functions -------------*/
struct node* llist_node_linear_search(struct llist* p_ll,
                                      struct node* p_node,
                                      llist_node_cmp_cb* p_func)
{
    struct node* p_nodet = p_ll->p_head;

    // while EOList ( end of list )
    while (NULL != p_nodet)
    {
        if (p_func(p_node, p_nodet) == 0)
            return p_nodet;
        else
            p_nodet = p_nodet->p_next;
    }
    return NULL;
}

/* ---------  sort functions -------------*/
bool llist_node_bubble_sort(struct llist* p_ll,
                            llist_node_cmp_cb* p_func)
{
    struct node* p_node;
    bool flag = true;

    while (flag == true)
    {
        flag = false;
        p_node = p_ll->p_head;
        while (p_node->p_next != NULL)
        {
            if (p_func(p_node, p_node->p_next) > 0)  // p1> p2
            {
                llist_node_switch(p_ll, p_node, p_node->p_next);
                p_node = p_node->p_prev;
                flag = true;
            }
            p_node = p_node->p_next;
        }
    }
    return true;
}

/* ---------  debug functions -------------*/
void llist_debug_print_node_params(struct node* p_node,
                                   llist_node_print_cb* p_func)
{
    printf("\n\nnode data: ");
    printf("\nnode = %p ", (p_node));
    printf("\nnode next = %p ", (p_node->p_next));
    printf("\nnode prev = %p ", (p_node->p_prev));
    p_func(p_node);
}

void llist_debug_print_llist_params(struct llist* p_llist)
{
    printf("\n\nllist data: ");
    printf("\nhead pointer = %p ", (p_llist->p_head));
    printf("\ntail pointer = %p ", (p_llist->p_tail));
}

void llist_debug_print_llist_all_nodes(struct llist* p_llist,
                                       llist_node_print_cb* p_func)
{
    struct node* p_nodet = p_llist->p_head;

    printf("\nPrinting entire list:");
    llist_debug_print_llist_params(p_llist);
    while (p_nodet != NULL)
    {
        llist_debug_print_node_params(p_nodet, p_func);
        p_nodet = p_nodet->p_next;
    }
    printf("\n-------------------------------");
}
