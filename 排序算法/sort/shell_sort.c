/* shell_sort.c
 * purpose: sort some numbers.
 * efficency: O(n^(3/2)) in worse condition.
 * better than insert_sort, select_sort and bubble_sort.
 * divide these numbers into sereral groups, use insert_sort() inner group. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 20

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

void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;

	do 
	{
		increment = increment/5 + 1; //no fixed method to deside increment, but be sure the least increment is 1.
		for(i = increment + 1; i <= L->length; i++) //inserting-sort inter grop
		{
			if(L->r[i] < L->r[i-increment])
			{
				L->r[0] = L->r[i];

				for(j = i-increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
					L->r[j+increment] = L->r[j];

				L->r[j+increment] = L->r[0];
			}
		}
	} while (increment > 1);
}

main()
{
	SqList L;
	int i;

	L.length = MAXSIZE-1; //number of data, r[0] as the "temp variable or wathcer"
	
	srand((unsigned int)time(NULL)); //initliaze seeds, or the default seed will cause the same number.
	for(i = 1; i <= L.length; i++)
	{
		L.r[i] = rand()%1000;
	}
	puts("before sorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}

	ShellSort(&L);
	puts("\nsorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}