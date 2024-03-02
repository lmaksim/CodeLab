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
	int	inerv;
	/*value to be set as param in *pf*/
	int idx;
	/*pf to be called up to time up with idx value*/
	void (*pfuc)(int);
	
	/*time up value*/
	double timeup;
	/*overflow flag*/
	bool ovrfl;
	/*pointer to next timer*/
	struct timer* pnext;
};

bool timer_init(void);

bool timer_start(struct timer* ptmr);

bool timer_di_update(void);

//-----------------------
bool demo_isr_intr_1ms();

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __TIMER_H__