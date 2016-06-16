/* heap_sort.c
 * purpose: sort some numbers.
 * efficiency: O(nlogn) in worse condition and average case.
 * good: better than shell_sort, insert_sort, select_sort and bubble_sort.
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

//用二叉树的层序遍历进行查找并替换
void HeapAdjust(SqList *L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
  
	for(j = 2*s; j <= m; j *= 2) //j为s的left child的位置
	{
		if(j < m && L->r[j] < L->r[j+1]) //得到子结点中较大的结点的位置
			++j;

		if(temp >= L->r[j]) //care j changed or not?
			break;

		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;
}

void HeapSort(SqList *L)
{
	int i;

	//初始化大根堆
	for(i = L->length/2; i > 0; i--)
		HeapAdjust(L, i, L->length);

	for(i = L->length; i > 1; i--)
	{
		swap(L, 1, i); //交换堆顶元素与最后一个元素
		HeapAdjust(L, 1, i-1);
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

	HeapSort(&L);
	puts("\nsorted:");
	for(i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i]);
	}
	putchar('\n');
}