/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "timer_test.h"
#include "middlware/timer.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/**********************************/
void tmr_fuct_cb(int idx)
{
	printf("timer is up, value is %d\n", idx);
}

int timer_main(void)
{
	struct timer *ptmr;

	timer_init();

	for (int i = 1; i < 10; i = i + 2)
	{
		ptmr = (struct timer*)malloc(sizeof(struct timer));
		if (ptmr == NULL)
			return false;
		ptmr->inerv = i; //10ms
		ptmr->pfuc = tmr_fuct_cb;
		ptmr->idx = i;
		ptmr->pnext = NULL;
		timer_start(ptmr);
	}

	for (int i = 10; i > 0; i = i - 2)
	{
		ptmr = (struct timer*)malloc(sizeof(struct timer));
		if (ptmr == NULL)
			return false;
		ptmr->inerv = i; //10ms
		ptmr->pfuc = tmr_fuct_cb;
		ptmr->idx = i;
		ptmr->pnext = NULL;
		timer_start(ptmr);
	}

	for (int i = 11; i < 15; i = i ++)
	{
		ptmr = (struct timer*)malloc(sizeof(struct timer));
		if (ptmr == NULL)
			return false;
		ptmr->inerv = i; //10ms
		ptmr->pfuc = tmr_fuct_cb;
		ptmr->idx = i;
		ptmr->pnext = NULL;
		timer_start(ptmr);
	}
	
	while (true)
	{
		clock_t clk;
		
		clk = clock() / CLOCKS_PER_SEC;
		while (true)
		{
			if (clk != clock() / CLOCKS_PER_SEC)
			{
				clk = clock() / CLOCKS_PER_SEC;
				//call each 1 sec
				demo_isr_intr_1ms();
				break;
			}
		}
	}
}

/**********************************/