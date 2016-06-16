 /* @TITLE: 实现堆排序算法, 它是一种树形选择排序算法
  * @性能：时间复杂度O(nlogn)， 空间复杂度O(1)
  * @TIME:2015-6-25
  * @FROM:算法导论
  * @AUTHOR:PengSc
  */
#include <stdio.h>
#define PARENT(i) (i/2) //求父节点索引
#define LEFT(i)	(2*i)	//求左子节点索引
#define RIGHT(i) (2*i+1)//求右子节点索引

/* 维护堆的性质 */
void maxHeapfy(int a[], int n, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = i; //左右子节点中较大的一个

	if(l < n && a[l] > a[i])
		largest = l;

	if(r < n && a[r] > a[largest])
		largest = r;

	if(largest != i){ //交换
		int tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;
		maxHeapfy(a, n, largest); //递归处理子结构
	}
}

/* 建立大顶堆， 逻辑上是大顶堆，物理存储上是数组
 * a[]表示待建立大顶堆的数组
 * n为数组大小
 */
void buildMaxHeap(int a[], int n)
{//不必从n-1开始，因为其LEFT和RIGHT总是不存在
	for(int i = n/2; i >= 0; i--){ 
		maxHeapfy(a, n, i);
	}
}

/**性能：时间复杂度O(nlogn), 空间复杂度O(1)
 */
void heapSort(int a[], int n)
{
	buildMaxHeap(a, n); //建完大顶堆后，a[0]最大
	for(int i = n-1; i >= 0; i--){
		int tmp = a[i]; //把最大的元素放最后
		a[i] = a[0];
		a[0] = tmp;
		
		maxHeapfy(a, i, 0); //堆大小-1
	}
}

int main()
{
	int a[] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 1};
	//int a[] = {10};
	//int a[] = {10, 5};
	int n = sizeof(a)/sizeof(int);
	heapSort(a, n);
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	putchar('\n');
}
