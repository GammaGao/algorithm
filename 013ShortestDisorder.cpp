/* 题目：给定一个整数数组，编写一个函数，找出索引p和q，只要将m和n之间的元素排好序
 *		整个数组就是有序的（默认递增）。注意q-p(p <= q)越小越好，找出最短的子序列。
 * TIME：2015-5-3
 */
#include <iostream>
using namespace std;

static int err;

/* 找出递增序列0 至 start */
int findIncreaseSubsequence(int a[], int n)
{
	int i = 1;
	while(i < n && a[i-1] < a[i])
		i++;
	return i-1;
}

/* 找出递减序列end 至 n-1 */
int findDecreaseSubsequence(int a[], int n)
{
	int i = n-2;
	while(i >= 0 && a[i] < a[i+1])
		i--;
	return i+1;
}

/* 找出给定序列中最大值 */
int findMaxOfSubsequence(int a[], int n, int i, int j)
{
	if(i > j || i < 0 || j >= n){
		err = -1;
		return err;
	}

	int max = a[i];
	while(i <= j){
		if(max < a[i])
			max = a[i];
		i++;
	}
	return max;
}

/* 找出给定序列中的最小值 */
int findMinOfSubsequence(int a[], int n, int i, int j)
{
	if(i > j || i < 0 || j >= n){
		err = -1;
		return err;
	}

	int min = a[i];
	while(i <= j){
		if(min > a[i])
			min = a[i];
		i++;
	}
	return min;
}

/* 母函数，找出最短的子序列
 * 思路：例如：1,2,4,7,10,11,7,12,6,7,16,18,19，先找出开头和结尾的递增子序列：
		1,2,4,7,10 //a[start]=10，left部分
		7,12 //midlle部分
		6,7,16,18,19 //a[end]=6，注意它比a[start]更小，right部分
		找出middle部分和right部分的最小值，左移start直到a[start]<=min
		找出middle部分和left部分的最大值，右移end直到a[end]>=max，那么start+1和end-1即为所求。
 * 性能：时间复杂度O(n)
 */
void findShortestSubsequence(int a[], int n, int *p, int *q)
{
	if(a == NULL || n <= 0){
		err = -2;
		return;
	}

	if(n == 1){
		*p = 0; 
		*q = 0;
	}
	
	int start = findIncreaseSubsequence(a, n);
	int end = findDecreaseSubsequence(a, n);
	int max, min;
	if(start > end){ //已排好序
		*p = 0;
		*q = 0;
	}
	/* start表示左递增序列的末尾索引，end表示右递增序列的初始索引
	 * 不存在start==end这种情况
	 */
	else if(start < end){ //尚未排好序
		min = findMinOfSubsequence(a, n, start+1, n-1); //右边递增序列可能存在比中间序列更小的值
		max = findMaxOfSubsequence(a, n, 0, end-1); //左边序列可能存在比中间序列更大的值
		while(start >= 0 && a[start] > min)
			start--;
		start++;
		while(end < n && a[end] < max)
			end++;
		end--;
		*p = start;
		*q = end;
	}
}

int main()
{
	/* 以下测试用例均通过 */
//	int a[] = {100};
//	int a[] = {1,2};
//	int a[] = {10,2,1};
//	int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
//	int a[] = {1, 2, 4, 7, 10, 20, 7, 12, 6, 7, 16, 18, 19};
//	int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 2, 7, 16, 18, 19};
//	int a[] = {1, 2, 4, 7, 10, 11, 12, 13, 5, 7, 16, 18, 19};
	int a[] = {1, 2, 4, 7, 10, 11, 12, 13, 5, 7, 16, 18, 19};

	int p, q;
	int n = sizeof(a)/sizeof(int);
//	cout << findIncreaseSubsequence(a, n) << endl;
//	cout << findDecreaseSubsequence(a, n) << endl;
//	cout << findMaxOfSubsequence(a, n, 0, 12) << endl;
//	cout << findMinOfSubsequence(a, n, 0, 12) << endl;
	findShortestSubsequence(a, n, &p, &q);
	cout << "<" << p << "," << q << ">" << endl;
}
