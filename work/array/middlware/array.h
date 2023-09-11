/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stddef.h>
#include <stdbool.h>

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
struct fifo
{

  unsigned char* p_head; // init at second elememt
  unsigned char* p_tail; // init at first elememt
  bool empty;         // init false

};

/* ============= function pointers type defs ============== */
/* Function typedef to be used for element compare action.
 * Must be implemented by user , all results are related for
 * first element as compare to second */
typedef int (arr_elm_cmp_cb)(unsigned char*, unsigned char*);

/* Function typedef to be used for element switch operation.
 * Must be implemented by user */
typedef void (arr_elm_switch_cb)(unsigned char*, unsigned char*);

/* Function typedef to be used for element data copy,
 * copy second element to first
 * Must be implemented by user */
typedef void (arr_elm_cpy_cb)(unsigned char*, unsigned char*);

/* Function typedef to be used for element data print
 * Must be implemented by user */
typedef void (arr_elm_prt_cb)(unsigned char*);

/* ============= search functions ============== */
unsigned char* array_linear_search(unsigned char* p_arr,
                                   size_t num,
                                   size_t size,
                                   unsigned char* p_elm,
                                   arr_elm_cmp_cb* p_cmpf);

unsigned char* array_binary_search(unsigned char* p_arr,
                                   size_t num,
                                   size_t size,
                                   unsigned char* p_elm,
                                   arr_elm_cmp_cb* p_cmpf);

/* ============= sort functions ============== */
/* BFS */
void array_buble_sort(unsigned char* p_arr,
                      size_t num,
                      size_t size,
                      arr_elm_cmp_cb* p_cmpf,
                      arr_elm_switch_cb* p_swf);

void array_insertion_sort(unsigned char* p_arr,
                          size_t num,
                          size_t size,
                          arr_elm_cmp_cb* pfunc,
                          arr_elm_switch_cb* p_swf);

void array_selection_sort(unsigned char* p_arr,
                          size_t num,
                          size_t size,
                          arr_elm_cmp_cb*,
                          arr_elm_switch_cb* p_swf);

void array_mearge_sort(unsigned char* p_arr,
                       size_t num,
                       size_t size,
                       arr_elm_cmp_cb* p_cmpf,
                       arr_elm_switch_cb* p_swf);

void array_quick_sort(unsigned char* p_arr,
                      size_t num,
                      size_t size,
                      arr_elm_cmp_cb*,
                      arr_elm_switch_cb* p_swf);

/* ============= fifo functions ============== */
void array_next_elm(unsigned char** p_elm,
                    size_t num,
                    size_t size,
                    unsigned char* p_start);

bool array_fifo_push(unsigned char* p_arr,
                     size_t num,
                     size_t size,
                     struct fifo* p_fifo,
                     unsigned char* p_elm,
                     arr_elm_cpy_cb* p_cpyf);

bool array_fifo_pop(unsigned char* p_arr,
                    size_t num,
                    size_t size,
                    struct fifo* p_fifo,
                    unsigned char* p_elm,
                    arr_elm_cpy_cb* p_cpyf);

/* ============= debug functions ============= */
void array_print_all(unsigned char* p_arr,
                     size_t num,
                     size_t size,
                     arr_elm_prt_cb* p_prtf);

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __ARRAY_H__
