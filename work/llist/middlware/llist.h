/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#ifndef __LLIST_H__
#define __LLIST_H__

#include <stddef.h>
#include <stdbool.h>

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
struct node
{
    void* p_data;
    struct node* p_next;
    struct node* p_prev;

};

struct llist
{
    struct node* p_head;
    struct node* p_tail;

};

/* ============= function pointers type defs ============== */
/* Function typedef to be used for element compare action.
 * Must be implemented by user , all results are related for
 * first element as compare to second*/
typedef char (llist_node_cmp_cb) (struct node*,
                                  struct node*);

/* Function typedef to be used for element data print (debug).
 * Must be implemented by user*/
typedef void (llist_node_data_cb)(struct node*);

/*============== linked list functions ==============*/
/* in case there is empty link list, adds first element
   otherwise add to the end of list */
bool llist_node_append(struct llist* p_ll,
                       struct node* p_node);

/* remove does not free memory , just takes out element
 * from the linked list */
bool llist_node_remove(struct llist* p_ll,
                       struct node* p_node);

/* insert p_node before p_nodeb*/
bool llist_node_insert(struct llist* p_ll,
                       struct node* p_nodeb,
                       struct node* p_node);

/* llist_node_switch_nodes: switch two nodes
 * Important:
 * 1. p_nodef must be prior nodes.
 * 2. both nodes must be consecutive.
 */
bool llist_node_switch(struct llist* p_ll,
                       struct node* p_nodef,
                       struct node* p_nodes);

/* ============ search functions =================*/
struct node *llist_node_linear_search(struct llist* p_ll,
                                      struct node* p_node,
                                      llist_node_cmp_cb* p_fc);

/* ============  sort functions ==================*/
bool llist_node_bubble_sort(struct llist* p_ll,
                            llist_node_cmp_cb *p_fc);

/* ============= debug functions =================*/
void llist_debug_print_node_params(struct node* p_node,
                                   llist_node_data_cb* p_fc);

void llist_debug_print_llist_params(struct llist* p_ll);

void llist_debug_print_llist_all_nodes(struct llist* p_ll,
                                       llist_node_data_cb* p_fc);

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __LLIST_H__
