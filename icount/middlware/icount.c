#include <stdlib.h>
#include <stdbool.h>
#include "icount.h"
  
int mark_island(struct mxilends* mx)
{
#define MX_ELM(i,j) (mx->mtx + (i * mx->cols) + j)

	int rs = 0, rt = 0, cs = 0, ct = 0 ,cn = 0;
	bool flag;

	for (int i = 0; i < mx->rows; i++)
		for (int j = 0; j < mx->cols; j++)
		{
			/*find island start*/ 
			if (*MX_ELM(i, j) == X_VAL)
			{
				/*define boundaries*/ 
				{
					if (i == 0)
					{
						rs = 0;
						rt = 1;
					}
					else if (i == mx->rows - 1)
					{
						rs = i - 1;
						rt = i;
					}
					else
					{
						rs = i - 1;
						rt = i + 1;
					}
					if (j == 0)
					{
						cs = 0;
						ct = 1;
					}
					else if (j == mx->cols - 1)
					{
						cs = j - 1;
						ct = j;
					}
					else
					{
						cs = j - 1;
						ct = j + 1;
					}
				}

				flag = false;
				for (int x = rs; x <= rt; x++)
					for (int y = cs; y <= ct; y++)
					{
						if (*MX_ELM(x, y) != X_VAL && *MX_ELM(x, y) != 0)
						{
							*MX_ELM(x, y) = cn;
							flag = true;
						}
					}

				if (flag == false)
					cn++; 
				
				for (int x = rs; x <= rt; x++)
					for (int y = cs; y <= ct; y++)
					{
						if (*MX_ELM(x, y) != 0)
							(*MX_ELM(x, y)) = cn;
					}
			}
		}
	return cn;
}