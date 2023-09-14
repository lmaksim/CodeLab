/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
#ifndef __LLIST_H__
#define __LLIST_H__

#include <stddef.h>
#include <stdbool.h>

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
struct node
{
    struct node* p_next;
    struct node* p_prev;

    void* p_data;
};

struct llist
{
    struct node* p_head;
    struct node* p_tail;

};

/* ============= function pointers type defs ============== */
/* Function typedef to be used for nodes compare.
 * Must be implemented by user, the
 * first node as compare to second
 *  >0 - first node > second
 *  0< - first node < second
 *  =0 - first node = second */
typedef int (llist_node_cmp_cb) (struct node*,
                                  struct node*);

/* Function typedef to be used for node data print (debug).
 * Must be implemented by user*/
typedef void (llist_node_print_cb)(struct node*);

/*============== linked list functions ==============*/
/* in case there is empty link list, adds first element
   otherwise add to the end of list */
bool llist_node_append(struct llist*,
                       struct node*);

/* remove does not free memory, just takes out element
 * from the linked list */
bool llist_node_remove(struct llist*,
                       struct node*);

/* insert first node (prm 2) before
*  second parameter node (prm 3)*/
bool llist_node_insert(struct llist*,
                       struct node*,
                       struct node*);

/* llist_node_switch_nodes:
 * Important:
 * both nodes must be consecutive */
bool llist_node_switch(struct llist*,
                       struct node*,
                       struct node*);

/* ============ search functions =================*/
struct node *llist_node_linear_search(struct llist*,
                                      struct node*,
                                      llist_node_cmp_cb*);

/* ============  sort functions ==================*/
bool llist_node_bubble_sort(struct llist*,
                            llist_node_cmp_cb*);

/* ============= debug functions =================*/
void llist_debug_print_node_params(struct node*,
                                   llist_node_print_cb*);

void llist_debug_print_llist_params(struct llist*);


void llist_debug_print_llist_all_nodes(struct llist*,
                                       llist_node_print_cb*);

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __LLIST_H__
