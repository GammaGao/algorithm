#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 30 

/*
 * 快速排序算法的两个主要步骤，分割（Partition和QuickSort）
 */
typedef unsigned short u16;
u16 Partition(u16 A[],u16 index[], u16 p,u16 q);
u16 QuickSort(u16 A[],u16 index[], u16 p,u16 q);

u16 main()
{
    u16 a[MAX], index[MAX];
    u16 i;
    srand((u16)time(0));
    for(i = 0;i<MAX;i++)
    {
	a[i] = rand() % 100;
    }
    for(i = 0;i<MAX;i++) {
       index[i] = i;
       //pru16f("%d ",a[i]);
	printf("%d:%d ",a[i], index[i]);
    }

    printf("\nsort后:\n");

    QuickSort(a,index, 0,MAX-1);
    for(i = 0;i<MAX;i++)
	printf("%d:%d ",a[i], index[i]); //第二个为索引
    printf("\n");

    return 0;
}

/*
 * Partition步骤中哨兵选取的是最后一个元素作为哨兵
 */
u16 Partition(u16 A[],u16 index[], u16 p,u16 q)
{
    u16 i,j,x, x1, t;
    x = A[q];
    x1 = index[q];
    i = p-1;
    for(j = p;j<=q;j++) {
	if(A[j] < x)
	{
	    i++;
	    t = A[j];
	    A[j] = A[i];
	    A[i] = t;

	    t = index[j]; //索引交换
	    index[j] = index[i];
	    index[i] = t;
	}
    }
    A[q] = A[i+1];
    A[i+1] = x;

    index[q] = index[i+1]; //索引交换
    index[i+1] = x1;

    return i+1;
}

/*
 * 递归调用的QuickSort程序
 */ 
u16 QuickSort(u16 A[],u16 index[], u16 p,u16 r)
{
    if(p<r)
    {
        u16 q = Partition(A,index, p,r);
	QuickSort(A,index, p,q-1);
        QuickSort(A,index, q+1,r);
    }
}
