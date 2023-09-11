/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/*************************************************/
void array_next_elm(unsigned char** p,
                    size_t n,
                    size_t s,
                    unsigned char* f)
{
  *p += s;
  if ( *p == f + n * s )
    *p = f;
}
/*************************************************/
/* ============= search functions ============== */
unsigned char* array_linear_search(unsigned char* p_arr,
                           size_t num,
                           size_t size,
                           unsigned char* p_elm,
                           arr_elm_cmp_cb* p_cmpf)
{
  unsigned char* p_curr;

  for (p_curr = p_arr; p_curr <
       p_arr + num * size; p_curr += size)
    if (p_cmpf(p_curr, p_elm) == 0)
      return (p_curr);

  return NULL;
}

unsigned char* array_binary_search(unsigned char* p_arr,
                           size_t num,
                           size_t size,
                           unsigned char* p_elm,
                           arr_elm_cmp_cb* p_cmpf)
{
  unsigned char* p_head = p_arr;
  unsigned char* p_tail = p_arr + size * num;
  unsigned char* p_curr;
  char ret;

  do
  {
    p_curr = p_head + ((p_tail - p_head) / 2) * size;
    ret = p_cmpf(p_elm, p_curr);

    if (ret == -1)
      p_tail = p_curr;
    else if (ret == 1)
      p_head = p_curr;
    else
      return p_curr;
  }
  while (p_head != p_tail);

  return NULL;
}

/* ============= sort functions ============== */
void array_buble_sort(unsigned char* p_arr,
                      size_t num,
                      size_t size,
                      arr_elm_cmp_cb* p_cmpf,
                      arr_elm_switch_cb* p_swf)
{
  unsigned char* p_curr;
  unsigned char* p_tail = p_arr + size * num;
  bool flag;

  do
  {
    flag = false;
    for (p_curr = p_arr; p_curr < p_tail - size; p_curr += size)
    {
      if (p_cmpf(p_curr, p_curr + size) == 1)
      {
        p_swf(p_curr, p_curr + size);
        flag = true;
      }
    }
  }
  while (flag == true);
}

void array_insertion_sort(unsigned char* p_arr,
                          size_t num,
                          size_t size,
                          arr_elm_cmp_cb* p_cmpf,
                          arr_elm_switch_cb* p_swf)
{
  unsigned char* p_curr;
  unsigned char* p_tail;
  unsigned char* p_head = p_arr;

  for (p_curr = p_head, p_tail = p_curr;
       p_curr != p_head + size * num;
       p_curr = p_tail)
  {
    while (p_curr != p_head)
    {
      if (p_cmpf(p_curr - size, p_curr) == 1)
      {
        p_swf(p_curr - size, p_curr);
        p_curr -= size;
      }
      else
        break;
    }
    p_tail += size;
  }
}

void array_selection_sort(unsigned char* p_arr,
                          size_t num,
                          size_t size,
                          arr_elm_cmp_cb* p_cmpf,
                          arr_elm_switch_cb* p_swf)
{
  /* Not Implemented */
}

void array_mearge_sort(unsigned char* p_arr,
                       size_t num,
                       size_t size,
                       arr_elm_cmp_cb* p_cmpf,
                       arr_elm_switch_cb* p_swf)
{
  /* Not Implemented */
}

void array_quick_sort(unsigned char* p_arr,
                      size_t num,
                      size_t size,
                      arr_elm_cmp_cb* p_cmpf,
                      arr_elm_switch_cb* p_swf)
{
  /* Not Implemented */
}

/* ============= fifo functions ============== */
bool array_fifo_push(unsigned char* p_arr,
                          size_t num,
                          size_t size,
                          struct fifo* p_fifo,
                          unsigned char* p_elm,
                          arr_elm_cpy_cb* p_cpyf)
{
  if ((p_fifo->p_head != p_fifo->p_tail) ||
      (p_fifo->empty == true))
  {
    p_cpyf(p_fifo->p_head, p_elm);
    array_next_elm(&p_fifo->p_head,
                   size, num, p_arr);
    p_fifo->empty = false;
    return true;
  }
  return false;
}

bool array_fifo_pop(unsigned char* p_arr,
                         size_t num,
                         size_t size,
                         struct fifo* p_fifo,
                         unsigned char* p_elm,
                         arr_elm_cpy_cb* p_cpyf)
{
  if (p_fifo->empty == false)
  {
    p_cpyf(p_elm, p_fifo->p_tail);
    array_next_elm(&p_fifo->p_tail,
                   num, size, p_arr);
    if (p_fifo->p_tail == p_fifo->p_head)
      p_fifo->empty = true;

    return true;
  }
  return false;
}
/* ============= debug functions ============= */
void array_print_all(unsigned char* p_arr,
                     size_t num,
                     size_t size,
                     arr_elm_prt_cb* p_prtf)
{
  unsigned char* p_curr;
  unsigned char* p_tail = p_arr + size * num;

  for (p_curr = p_arr; p_curr < p_tail; p_curr += size)
    p_prtf(p_curr);
}
