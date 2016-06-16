/* select_sort.c
 * purpose: sort some numbers.
 * efficency: O(n^2) in worse condition.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef enum{FALSE = 0, TRUE}Status;
typedef struct
{
	int r[MAXSIZE]; //r[0] store the temp variable or "watcher"
	int length;
}SqList;

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void SelectSort(SqList *L)
{
	int i, j;
	for(i = 1; i <= L->length; i++)
	{
		L->r[0] = L->r[i]; //r[0] as temp variable, others store data.
		for(j = i; j <= L->length; j++)
		{
			if(L->r[j] < L->r[0])
			{
				swap(L, 0, j);
				L->r[i] = L->r[0];
			}
		}
	}
}

main()
{
	SqList L;
	int i;

	L.length = MAXSIZE-1; //number of data, r[0] as the "temp variable or wathcer"
	
	srand(time(NULL)); //initliaze seeds, or the default seed will cause the same number.
	for(i = 1; i <= L.length; i++)
	{
		L.r[i] = rand()%100;
	}
	puts("before sorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}

	SelectSort(&L);
	puts("\nsorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}