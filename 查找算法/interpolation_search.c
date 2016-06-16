/* interpolation_search.c
 * purpose:	   suit for search a data in an evenly distributed table(均匀分布表).
 * efficiency: In worse condition, is O(logn). In best condition, is O(1). But in average conditon, 
			   it is better than binary_search()(折半).
 */
#include <stdio.h>

int Interpolation_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while(low <= high)
	{	//插值公式(key-a[low])/(a[high]-a[low])
		mid = low +(key-a[low])/(a[high]-a[low]) * (high-low);
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
	int a[] = {16, 53, 54, 75, 80, 99, 100, 110, 160, 161, 162};
	int res, need;

	need = 162;
	res = Interpolation_Search(a, sizeof(a)/sizeof(int), need);

	if(0 == res)
		fprintf(stderr, "Not found %d\n", need);
	else
		fprintf(stdout, "Has found %d\n", need);
}