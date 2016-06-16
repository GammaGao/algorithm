/* fibonacci_search.c
 * purpose:	   suit for search a data in an evenly distributed table(���ȷֲ���).
 * method:	   the principle of golden section(�ƽ�ָ�ԭ��).
 * efficiency: In worse condition, is O(logn). In best condition, is O(1). But in average conditon, 
			   it is better than binary_search()(�۰�).
 */
#include <stdio.h>

/*
* 쳲����������㷨, �O(logn)
*/
int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;

	while(n > F[k]-1) //����nλ��쳲��������е�λ��, 
		k++;

	for(i = n; i < F[k]-1; i++) //����������ֵ��ȫ
	{
		a[i] = a[n];
	}

	while(low <= high)
	{
		mid = low + F[k-1] - 1;
		if(key < a[mid])
		{
			high = mid -1;
			k = k-1;
		}
		else if(key > a[mid])
		{
			low = mid+1;
			k = k-2;
		}
		else
		{
			if(mid <= n)
			{
				return mid;
			}
			else
				return n;
		}
	}
}

int main()
{
	int a[] = {16, 53, 54, 75, 80, 99, 100, 110, 160, 161, 162};
	int res, need;

	need = 162;
	res = Fibonacci_Search(a, sizeof(a)/sizeof(int), need);

	if(0 == res)
		fprintf(stderr, "Not found %d\n", need);
	else
		fprintf(stdout, "Has found %d\n", need);
}