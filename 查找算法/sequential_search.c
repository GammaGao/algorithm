/* sequential_search.c
 * purpose:	   suit for search a data in unordered table.
 * efficiency: In worse and average condition, is O(n). In best condition, is O(1).
 */
#include <stdio.h>

/*
* ���ڱ�˳�����, ƽ��O(n) = ����O(n)
* �����ڲ��������, ���ݲ��Ҹ��ʲ�ͬ�����ײ��ҵķ���ǰ��
*/
int Sequential_Search(int *a, int n, int key)
{
	int i;

	a[0] = key;	//�����ڱ�, ���С���ɲ���ÿ�ζ��μ���Ƿ�Խ��
	i = n;	//ѭ�������β����ʼ
	while(a[i] != key)
	{
		i--;
	}

	return i;	//����0˵������ʧ��
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