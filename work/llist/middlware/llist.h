#include <stdbool.h>

struct node {
    /* Used for fifo and buffer data
    structure management */
    struct node *next;
    struct node *prev;

    void* data;
    void (*func_ptr_cmp)(void*, void*);
};

struct fifo {
    /* Used for fifo and buffer data
    structure management */
    struct node *head;
    struct node *tail;
    bool isempty;
};

//==============================================
/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
void llist_buff_init( struct node *head );

/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
void llist_buff_add( struct node *head, struct node* node );

/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
bool llist_buff_remove( struct node *head, struct node* node );

/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
llist_buff_sort( struct node *head );

/* Function finds element in the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
        /* Function sorts array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
void* llist_buff_pick( struct node *head, void *data );

//==============================================
/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
bool llist_fifo_init( struct llink* fifo );

/* Function inserts element to the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array (last element must be empty!!!)
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function compares elements
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
    void (*func_cpy)( void *elm1 , void *elm2) - function copy elm2 to elm1
        the function must be implemented by user */
bool llist_fifo_push( struct llink* fifo , struct node *node );

/* Function inserts element to the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array (last element must be empty!!!)
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function compares elements
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
    void (*func_cpy)( void *elm1 , void *elm2) - function copy elm2 to elm1
        the function must be implemented by user */

/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
bool llist_fifo_pop( struct llink* fifo, struct node *node );

/* Function removes element from the sorted array
   Parameters:
   void *arr - pointer to array to be sorted
   int size - size of array
   void *elm - pointer to element to be found
   char (*func_cmp)( void *elm1 , void *elm2) - function to be called for elements compare
        the function must return the following values:
        =0 - if elm1 = elm2
        >0 - if elm1 > elm2
        <0 - if elm1 < elm2
        the function must be implemented by user */
bool llist_fifo_is_empty( struct llink* fifo );

