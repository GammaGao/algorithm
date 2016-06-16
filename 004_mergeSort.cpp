#include <iostream>
using namespace std;

void merge(int a[], int p, int q, int r);

/* 归并排序算法循环实现 */
void mergeSort(int a[], int n)
{
	if(a == NULL || n <= 0) 
		return;
	for(int step = 2; step/2 < n; step *= 2){ //步长:2,4,8,16...，结束条件是步长
		for(int i = 0; i < n; i += step){ //每一段
			int start = i; //段首
			int end = i + step - 1; //段尾
			if(i + step < n){ //最后一段可能出现元素不够的情况
				int mid = (start + end) / 2;
				merge(a, start, mid, end);
			}
			else{ //如果最后一次，元素个数不够够一整段
				if(i + step/2 -1 >= n-1) //如果够一半，这一半一定是有序的
					break;
				merge(a, i, i + step/2 - 1, n - 1);
			}
		}
	}
}

/* 合并两个数组 */
void merge(int a[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *c1 = new int[n1];
	int *c2 = new int[n2];
	for(int i = 0; i < n1; i++)
		c1[i] = a[p + i];
	for(int i = 0; i < n2; i++)
		c2[i] = a[q + 1 + i];

	int i = 0, j = 0, k = p;
	while(i < n1 && j < n2){
		if(c1[i] <= c2[j])
			a[k++] = c1[i++];
		else
			a[k++] = c2[j++];
	}
	if(i < n1){
		while(i < n1)
			a[k++] = c1[i++];
	}

	if(j < n2){
		while(j < n2)
			a[k++] = c2[j++];
	}

	delete c1, c2;
}

int main()
{
//	int a[] = {23}; // 1
//	int a[] = {2, 10};
//	int a[] = {10, 2};
//	int a[] = {10, 2, 11};
//	int a[] = {11, 10, 2};
//	int a[] = {12, 10, 15, 13};
//	int a[] = {12, 10, 15, 11};
//	int a[] = {23, 10, 8, 5, 7};
//	int a[] = {23, 10, 8, 5, 7, 21};
//	int a[] = {23, 10, 8, 5, 7, 21, 100};
	int a[] = {23, 10, 8, 5, 7, 21, 18, 100};
	int n = sizeof(a)/sizeof(int);
	mergeSort(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
