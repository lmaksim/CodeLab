#include <stdbool.h>
#include <stdio.h>
#include "timer.h"

struct timer* pact; 
struct timer* pcrr;
struct timer* pprv;
struct timer* pnew;

bool cntrf; 
double cntr;

bool timer_init(void)
{
	printf("file name: %s, line number = %d.\n", __FILE__, __LINE__); 
	cntr = 0;
	pnew = NULL;
	pcrr = NULL;
	pprv = NULL;
	pact = NULL;
	return true;
}

bool timer_start(struct timer *ptmr)
{
	pnew = ptmr;
	pnew->timeup = cntr + ptmr->inerv; 
	if (pnew->timeup < cntr)
		pnew->ovrfl = true;
	else
		pnew->ovrfl = false;
	
	if (pact == NULL)
	{
		pact = pnew;
		return true;
	}
		
	pcrr = pact;
	pprv = pcrr; 
	while (pcrr != NULL)
	{
		if (((pcrr->ovrfl == pnew->ovrfl) && 
			 (pcrr->timeup < pnew->timeup)) || 
			((pcrr->ovrfl == false) && 
			 (pnew->ovrfl == true)))
		{
			pprv = pcrr;
			pcrr = pcrr->pnext;
			continue;
		}
		else
		{
			if (pcrr == pact)
			{
				while (cntrf == true);
				pnew->pnext = pcrr;
				pact = pnew;
				break;
			}
			break;
		}
	}
	if (pprv != pcrr)
	{
		pnew->pnext = pprv->pnext;
		pprv->pnext = pnew;
	}
	return true;
}

bool timer_di_update(void)
{
	cntrf = true;
	cntr ++;
	if (pact == NULL)
	{
		printf("file name: %s, line number = %d.\n", __FILE__, __LINE__);
		return false;
	}
	
	if (cntr == pact->timeup)
	{
		pact->pfuc(pact->idx);
		if (pact->pnext != NULL)
			pact = pact->pnext;
		printf("file name: %s, line number = %d.\n", __FILE__, __LINE__);
	}
	cntrf = false;
	return true;
}

//-----------------------
bool demo_isr_intr_1ms()
{
	printf("file name: %s, line number = %d.\n", __FILE__, __LINE__);
	timer_di_update();
}