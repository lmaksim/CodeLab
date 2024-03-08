/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
/**********************************/
#include "timer_test.h"
#include "middlware\timer.h"
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
	timer_init();

	for (int i = 1; i < 10; i = i + 2)
	{
		timer_start(i, tmr_fuct_cb, i);
	}

	timer_start(0, tmr_fuct_cb, 0);

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