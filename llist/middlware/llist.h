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

/* ============= function type definitions ============== */
/* Type definition for the function that 
 * compares between two nodes (must be implemented by user).
 * The returned resul must be as following:
 *  >0 - first > second
 *  0< - first < second
 *  =0 - first = second 
 */
typedef int (llist_node_cmp_cb) (struct node*,
                                 struct node*);

/* Type definition for the function that 
 * prints node data (must be implemented by user).  
 */
typedef void (llist_node_print_cb)(struct node*);

/*============== linked list functions ==============*/
/* Function that adds the new node to the end of the link,
 * in case the link is empty, creates new list as the
 * first element  */
bool llist_node_append(struct llist*,
                       struct node*);

/* Function that used to remove link from the list. */
bool llist_node_remove(struct llist*,
                       struct node*);

/* Function that used to insert new node (parameter 2) before
*  specific node (parameter 3) in the list (parameter 1)*/
bool llist_node_insert(struct llist*,
                       struct node*,
                       struct node*);

/* Function switches between two consecutive nodes in :
 * the list */
bool llist_node_switch(struct llist*,
                       struct node*,
                       struct node*);

/* ============= search functions ============== */
/* Function searches for the node in the list using
 * liniar search.
   Note: llist_node_cmp_cb must be implemented by user */
struct node *llist_node_linear_search(struct llist*,
                                      struct node*,
                                      llist_node_cmp_cb*);

/* ============= sort functions ============== */
/* Function sort the list using bubble search.
   Note: llist_node_cmp_cb must be implemented by user */
bool llist_node_bubble_sort(struct llist*,
                            llist_node_cmp_cb*);

/* ============= debug functions ============= */
/* Function print node data
   Note: llist_node_print_cb must be implemented by user */
void llist_debug_print_node_params(struct node*,
                                   llist_node_print_cb*);

/* Function print list paramters data */
void llist_debug_print_llist_params(struct llist*);

/* Function print all nodes data in a list
   Note: llist_node_print_cb must be implemented by user */
void llist_debug_print_llist_all_nodes(struct llist*,
                                       llist_node_print_cb*);

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __LLIST_H__
