/* binary_search.c
 * purpose:	   suit for search a data in an ordered table.
 * efficiency: In worse condition, is O(logn). In best condition, is O(1).
 */
#include <stdio.h>

/*
 * 要求有序表，且不适用于频繁插入或删除的有序表(维护有序表开销太大)
 */
int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while(low <= high)
	{
		mid = (low + high)/2;
		//printf("mid:%d\n", mid);
		if(key < a[mid])
		{
			high = mid-1;
		}
		else if(key > a[mid])
		{
			low = mid+1;
		}
		else
			return mid;
	}
}

int main()
{
	int a[] = {62, 88, 16, 58, 47, 35, 73, 51, 99, 37, 93};
	int res, need;

	need = 88;
	res = Binary_Search(a, sizeof(a)/sizeof(int), need);

	if(0 == res)
		fprintf(stderr, "Not found %d\n", need);
	else
		fprintf(stdout, "Has found %d\n", need);
}