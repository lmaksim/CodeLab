/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#ifndef __TIMER_H__
#define __TIMER_H__

#include <stddef.h>
#include <stdbool.h>


 /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

struct timer
{
	/*timer inerval*/
	int	intrv;
	/*value to be set as param in *pf*/
	int value;
	/*pf to be called up to time up with idx value*/
	void (*pfuc)(int);
	/*timer index*/
	int	index;
	
	/*time up value*/
	double timeup;
	/*overflow flag*/
	bool ovrfl;
	/*timer status true for active, false for inactive*/
	bool status;
};

bool timer_init(void);

int timer_create(struct timer* ptmr);

bool timer_delete(int idx);

bool timer_start(int idx, int intrv);

double timer_interval_get(int idx);

bool timer_stop(int idx);

//-----------------------
void timer_di_update(void);

void demo_isr_intr_1ms();

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __TIMER_H__