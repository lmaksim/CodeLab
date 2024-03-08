#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "..\..\llist\middlware\llist.h"

struct counter {
	double cntr;
	bool busy;
};

struct timer
{
	/*value to be set as param in *pf*/
	int value;
	/*pf to be called up to time up with idx value*/
	void (*pfuc)(int);
	/*time up value*/
	double timeup;
	/*overflow flag*/
	bool ovrfl;
};

struct llist s_timers;
struct counter s_cntr;

int timer_node_cmp(struct node* p_n1, struct node* p_n2)
{
	if (((struct timer*)(p_n1->p_data))->ovrfl == ((struct timer*)(p_n2->p_data))->ovrfl)
	{
		if (((struct timer*)(p_n1->p_data))->timeup > ((struct timer*)(p_n2->p_data))->timeup)
			return 1;
		if (((struct timer*)(p_n1->p_data))->timeup > ((struct timer*)(p_n2->p_data))->timeup)
			return -1;
		else
			return 0;
	}
	if (((struct timer*)(p_n1->p_data))->ovrfl == true &&
		((struct timer*)(p_n2->p_data))->ovrfl == false)
		return 1;
	else
		return -1;
}

bool timer_init(void)
{
	s_cntr.busy = false;
	s_cntr.cntr = 0;
	s_timers.p_head = NULL;
	s_timers.p_tail = NULL;
	return true;
}

bool timer_start(int interval, void (*pfuc)(int), int value)
{
	struct timer* p_tmr = (struct timer*)malloc(sizeof(struct timer));
	struct node* p_node = (struct node*)malloc(sizeof(struct node));
	if (p_tmr == NULL || p_node == NULL || interval == 0)
		return false;
	p_tmr->value = value;
	p_tmr->pfuc = pfuc;
	p_tmr->timeup = interval + s_cntr.cntr;
	p_tmr->ovrfl = false;
	if (p_tmr->timeup < s_cntr.cntr)
		p_tmr->ovrfl = true;
	p_node->p_data = p_tmr;
	while (s_cntr.busy == true); 
	llist_node_append(&s_timers, p_node);
	llist_node_bubble_sort(&s_timers, timer_node_cmp);
	return true;
}

void timer_di_update(void)
{
	s_cntr.busy = true;
	s_cntr.cntr++;
	s_cntr.busy = false;
	if (s_timers.p_head != NULL)
	{
			if (s_cntr.cntr == (((struct timer*)(s_timers.p_head->p_data))->timeup))
			{
				(((struct timer*)(s_timers.p_head->p_data))->pfuc((((struct timer*)(s_timers.p_head->p_data))->value)));
				if (s_timers.p_head->p_next != NULL)
				{
					struct node* p_node = s_timers.p_head;
					s_timers.p_head = s_timers.p_head->p_next;
					llist_node_remove(&s_timers, p_node);
					free((struct timer*)p_node);
				}
			}
	}
}

//-----------------------
void demo_isr_intr_1ms()
{
	timer_di_update();
}