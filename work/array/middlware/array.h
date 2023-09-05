#include <stdbool.h>

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
void array_buff_sort( void **arr,
                 unsigned int size_of_arr,
                 char (*func_cmp)( void *elm1 , void *elm2));

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
void* array_buff_find( void **arr,
                      unsigned int size_of_arr,
                      void *elm,
                      char (*func_cmp)( void *elm1 , void  *elm2));

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
bool array_buff_insert( void **arr,
                       unsigned int arr_size,
                       void *elm,
                       char (*func_cmp)( void *elm1 , void *elm2));

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
bool array_buff_remove( void **arr,
                       unsigned int arr_size,
                       void *elm,
                       char (*func_cmp)( void *elm1 , void *elm2 ));

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
void array_fifo_write( void **arr,
                 unsigned int size_of_arr,
                 char (*func_cmp)( void *elm1 , void *elm2));

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
void* array_fifo_read( void **arr,
                      unsigned int size_of_arr,
                      void *elm,
                      char (*func_cmp)( void *elm1 , void  *elm2));

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
bool array_fifo_reset( void **arr,
                       unsigned int arr_size,
                       void *elm,
                       char (*func_cmp)( void *elm1 , void *elm2));
