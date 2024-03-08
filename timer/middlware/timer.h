/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#ifndef __TIMER_H__
#define __TIMER_H__

#include <stddef.h>
#include <stdbool.h>


 /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

bool timer_init(void);

bool timer_start(int intrv, void (*pfuc)(int), int val);

//-----------------------
void timer_di_update(void);

void demo_isr_intr_1ms();

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __TIMER_H__