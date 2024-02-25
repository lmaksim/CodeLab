/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

#include <stdio.h>
#include <conio.h>
#include "icount_test.h"
#include "middlware/icount.h"

/**********************************/


/**********************************/


int icount_main( void )
{
	char a[][4] = { {1,0,1,1},
					{0,1,0,0},
					{0,0,0,1},
					{1,1,0,0} };

	int rows = sizeof(a) / sizeof(a[0]);
	int cols = sizeof(a[0]) / sizeof(a[0][0]);

	char t[4][4] = { {0} };
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (a[i][j] == 1)
				t[i][j] = X_VAL;

	struct mxilends mx;
	mx.cols = cols;
	mx.rows = rows;
	mx.mtx = &t[0][0];

	int rcv = mark_island(&mx);
	printf("%d", rcv); 
	
	return 1;
    
}
