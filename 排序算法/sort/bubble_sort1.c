/* bubble_sort1.c
 * purpose: sort some numbers.
 * efficency: O(n^2) in worse condition also.
 * there are less comparing times because some data need not to exchange.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef enum{FALSE = 0, TRUE}Status;
typedef struct
{
	int r[MAXSIZE-1]; //r[0] store the temp variable or "watcher"
	int length;
}SqList;

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSort1(SqList *L)
{
	int i, j;
	Status flag = TRUE;

	for(i = 0; i < L->length && flag; i++)
	{
		flag = FALSE;
		for(j = 0; j < L->length - i - 1; j++)
		{
			if(L->r[j] > L->r[j+1])
			{
				swap(L, j, j+1);
				flag = TRUE; // if exchanged, set flag as TRUE
			}
		}
	}
}

main()
{
	SqList L;
	int i;

	L.length = MAXSIZE-1;
	
	srand(time(NULL)); //initliaze seeds, or the default seed will cause the same number.
	for(i = 0; i < L.length; i++)
	{
		L.r[i] = rand()%100;
	}
	puts("before sorted:");
	for(i = 0; i < L.length; i++)
	{
		printf("%d ", L.r[i]);
	}

	BubbleSort1(&L);
	puts("\nsorted:");
	for(i = 0; i < L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}