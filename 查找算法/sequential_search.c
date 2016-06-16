/* sequential_search.c
 * purpose:	   suit for search a data in unordered table.
 * efficiency: In worse and average condition, is O(n). In best condition, is O(1).
 */
#include <stdio.h>

/*
* 有哨兵顺序查找, 平均O(n) = 最坏情况O(n)
* 适用于查找无序表, 根据查找概率不同，容易查找的放在前面
*/
int Sequential_Search(int *a, int n, int key)
{
	int i;

	a[0] = key;	//设置哨兵, 编程小技巧不用每次都次检查是否越界
	i = n;	//循环数组从尾部开始
	while(a[i] != key)
	{
		i--;
	}

	return i;	//返回0说明查找失败
}

int main()
{
	int a[] = {62, 88, 16, 58, 47, 35, 73, 51, 99, 37, 93};
	int res, need;

	need = 88;
	res = Sequential_Search(a, sizeof(a)/sizeof(int), need);

	if(0 == res)
		fprintf(stderr, "Not found %d\n", need);
	else
		fprintf(stdout, "Has found %d\n", need);
}