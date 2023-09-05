#include <stdio.h>
#include <stddef.h>
#include "llist.h"

void swap( struct node* nodea, struct node *nodeb )
{
    nodea->next = nodeb->next;
    nodeb->next = nodea;
    nodeb->prev = nodea->prev;
    nodea->prev = nodeb;
}

void llist_buff_init( struct node *head )
{
    head->next = NULL;
    head->prev = NULL;
}

void llist_buff_add( struct node *head, struct node* node )
{
  while (head->next != NULL)
    head = head->next;

  head->next = node;
  node->prev = head;
  node->next = NULL;
}

bool llist_buff_remove( struct node *head, struct node* node )
{
    if (node->prev->next != NULL)
    {
        node->prev->next = NULL;
        node->prev = NULL;
    }
    head->next = NULL;
    return true;
}

llist_buff_sort( struct node *head )
{
    bool flag = true;
    while( head->next != NULL )
    {
        flag = false;
        while( flag == true )
        {
            if ( func_ptr_cmp(head, head->next) < 0 )
            {
                swap( head, head->next );
                flag = true;
            }
            head = head->next;
        }
    }
}

/*void* llist_buff_pick( struct node *head, void *data )
{
    return NULL;
}

bool llist_fifo_init( struct fifo* fifo )
{
    return true;
}

bool llist_fifo_push( struct fifo* fifo , struct node *node )
{
    return true;
}

bool llist_fifo_pop( struct fifo* fifo, struct node *node )
{
    return true;
}

bool llist_fifo_is_empty( struct fifo* fifo )
{
    return true;
}*/

