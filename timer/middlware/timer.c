#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "\Code\CodeLab\llist\middlware\llist.h"

bool cntrf; 
double cntr;
struct llist s_timers, *p_tmrs;
struct node s_timer, *p_actv, *p_new;
int idx;

int timer_index_get(void)
{
	return ++idx;
}

int timer_node_cmp(struct node* p_n1, struct node* p_n2)
{
	if (((struct timer*)(p_n1->p_data))->index > ((struct timer*)(p_n2->p_data))->index)
		return 1;
	if (((struct timer*)(p_n1->p_data))->index < ((struct timer*)(p_n2->p_data))->index)
		return -1;
	else
		return 0;
}

bool timer_init(void)
{
	printf("file name: %s, line number = %d.\n", __FILE__, __LINE__); 
	while (cntrf == true); 
	cntr = 0;
	idx = 0;
	p_tmrs = &s_timers;
	p_tmrs->p_head = NULL;
	p_tmrs->p_tail = NULL;
	p_tmrs->p_curr = NULL;
	p_actv = NULL;
	return true;
}

int timer_create(struct timer* p_tmr)
{
	p_new = (struct node*)malloc(sizeof(struct node));
	if (p_new == NULL)
		return false;
	p_new->p_data = p_tmr;
	p_new->p_next = NULL;
	p_new->p_prev = NULL;
	((struct timer*)(p_new->p_data))->index = timer_index_get();
	((struct timer*)(p_new->p_data))->status = false;

	return (llist_node_append(p_tmrs, p_new));
}

bool timer_delete(int idx)
{
	struct node s_tnode = {0};
	((struct timer*)(s_tnode.p_data))->index = idx;
	struct node* p_tmp = llist_node_linear_search(&s_timers, &s_tnode, timer_node_cmp);
	if (p_tmp != NULL)
		return (llist_node_remove(&s_timers, p_tmp));
	
	return false;
}

bool timer_start(int idx, int intrv)
{
	struct node s_tnode = {0};
	((struct timer*)(s_tnode.p_data))->index = idx;
	struct node* p_tmp = llist_node_linear_search(&s_timers, &s_tnode, timer_node_cmp);
	if (p_tmp != NULL)
	{
		((struct timer*)(p_tmp->p_data))->intrv = intrv;
		((struct timer*)(s_timers.p_curr->p_data))->status = true;
		while (cntrf == true);
		llist_node_bubble_sort(&s_timers, timer_node_cmp);
	}

	return true;
}

double timer_interval_get(int idx)
{
	struct node s_tnode = {0};
	((struct timer*)(s_tnode.p_data))->index = idx;
	struct node* p_tmp = llist_node_linear_search(&s_timers, &s_tnode, timer_node_cmp);
	if (p_tmp != NULL)
		return (((struct timer*)(p_tmp->p_data))->intrv);
	return false;
}

bool timer_stop(int idx)
{

	return true;
}

void timer_di_update(void)
{
	cntrf = true;
	cntr++;
	cntrf = false;
	if ((((struct timer*)(s_timers.p_curr->p_data))->status == true))
	{
		if (cntr == (((struct timer*)(s_timers.p_curr->p_data))->timeup))
		{
			(((struct timer*)(s_timers.p_curr->p_data))->pfuc((((struct timer*)(s_timers.p_curr->p_data))->index)));
			((struct timer*)(s_timers.p_curr->p_data))->status = false;
			if (s_timers.p_curr->p_next != NULL)
				s_timers.p_curr = s_timers.p_curr->p_next;
		}
	}
}

//-----------------------
void demo_isr_intr_1ms()
{
	printf("file name: %s, line number = %d.\n", __FILE__, __LINE__);
	timer_di_update();
}