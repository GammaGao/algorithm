/* merge_sort.c
 * purpose: sort some numbers.
 * efficiency: O(nlogn) in worse condition, average case and best condition.
 * good: better than shell_sort, insert_sort, select_sort and bubble_sort.
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

/* 将有序的SR[i:m],  SR[m+1:n]两个子序列归并到TR[i:n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, ln;
	for(j = m+1, k=i; i <= m && j <= n; k++) //将SR中记录由小到大归并入TR
	{
		if(SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}

	if(i <= m)
	{
		for(ln = 0; ln <= m-i; ln++) //剩余的SR[i:m]复制到TR[]
		//	TR[k+ln] = SR[i+ln];
			TR[k++] = SR[i+ln];
	}

	if(j <= n)
	{
		for(ln = 0; ln <= n-j; ln++) //剩余的SR[j:n]复制到TR[]
			//TR[k+ln] = SR[j+ln];
			TR[k++] = SR[j+ln];
	}
}

/* 二分归并，将SR[]排序为TR1[] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];

	if(s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s+t)/2; //将SR[s:t]平分SR[s:m]和SR[m+1:t]
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m+1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

//keep the same format as other sorting-algorithm, no other use.
//递归
void MergeSort(SqList *L)
{
	MSort(L->r, L->r, 1, L->length); //L->r[0] as other use.
}

void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;
	while(i <= n - 2*s + 1)
	{
		Merge(SR, TR, i, i+s-1, i+2*s-1);
		i += 2*s;
	}

	if(i < n-s+1)
	{
		Merge(SR, TR, i, i+s-1, n);
	}
	else
	{
		for(j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}
}

//非递归归并
void MergeSort2(SqList *L)
{
	int *TR = (int *)malloc(L->length*sizeof(int)); 
	int k = 1;
	while(k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		k = 2*k;
		MergePass(TR, L->r, k, L->length);
		k = 2*k;
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

	MergeSort2(&L);
	puts("\nsorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}
