/* insert_sort.c
 * purpose: sort some numbers.
 * efficency: O(n^2) in worse condition. In average case, only n^2 / 4 times moving-data. 
 * better than select_sort and bubble_sort.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void InsertSort(SqList *L)
{
	int i, j;
	for(i = 2; i <= L->length; i++)
	{
		if(L->r[i] < L->r[i-1])
		{
			L->r[0] = L->r[i];  //store the being-inserted data.

			for(j = i-1; L->r[j] > L->r[0]; j--)
				L->r[j+1] = L->r[j]; //move data back

			L->r[j+1] = L->r[0]; //insert the data in correct position.
		}
	}
}

main()
{
	SqList L;
	int i;

	L.length = MAXSIZE-1; //number of data, r[0] as the "temp variable or wathcer"
	
	srand((unsigned int)time(NULL)); //initliaze seeds, or the default seed will cause the same number.
	for(i = 1; i <= L.length; i++)
	{
		L.r[i] = rand()%100;
	}
	puts("before sorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}

	InsertSort(&L);
	puts("\nsorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}