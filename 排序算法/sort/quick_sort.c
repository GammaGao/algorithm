#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 30 

/*
 * ���������㷨��������Ҫ���裬�ָPartition��QuickSort��
 */
//typedef unsigned short u16;
int Partition(int A[],int index[], int p,int q);
int QuickSort(int A[],int index[], int p,int q);

int main()
{
    int a[MAX], index[MAX];
    int i;
    srand((int)time(0));
    for(i = 0;i<MAX;i++)
    {
	a[i] = rand() % 100;
    }
    for(i = 0;i<MAX;i++) {
       index[i] = i;
       //printf("%d ",a[i]);
	printf("%d:%d ",a[i], index[i]);
    }

    printf("\nsort��:\n");

    QuickSort(a,index, 0,MAX-1);
    for(i = 0;i<MAX;i++)
	printf("%d:%d ",a[i], index[i]); //�ڶ���Ϊ����
    printf("\n");

    return 0;
}

/*
 * Partition�������ڱ�ѡȡ�������һ��Ԫ����Ϊ�ڱ�
 */
int Partition(int A[],int index[], int p,int q)
{
    int i,j,x, x1, t;
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

	    t = index[j]; //��������
	    index[j] = index[i];
	    index[i] = t;
	}
    }
    A[q] = A[i+1];
    A[i+1] = x;

    index[q] = index[i+1]; //��������
    index[i+1] = x1;

    return i+1;
}

/*
 * �ݹ���õ�QuickSort����
 */ 
int QuickSort(int A[],int index[], int p,int r)
{
    if(p<r)
    {
        int q = Partition(A,index, p,r);
	QuickSort(A,index, p,q-1);
        QuickSort(A,index, q+1,r);
    }
}
