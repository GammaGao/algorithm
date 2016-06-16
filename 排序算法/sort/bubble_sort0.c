/* bubble_sort0.c
 * purpose: sort some numbers.
 * efficency: O(n^2) in worse condition
 * better: it can be optimized(see bubble_sort1.c).
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10
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

void BubbleSort0(SqList *L)
{
	int i, j;
	for(i = 0; i < L->length; i++)
	{
		for(j = 0; j < L->length - i - 1; j++)
		{
			if(L->r[j] > L->r[j+1])
				swap(L, j, j+1);
		}
	}
}

main()
{
	SqList L;
	int i;

	int r[] = {12, 13, 4, 3, 2, 5, 6, 87, 99};
	L.length = sizeof(r)/sizeof(r[0]);
	
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

	BubbleSort0(&L);
	puts("\nsorted:");
	for(i = 0; i < L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}