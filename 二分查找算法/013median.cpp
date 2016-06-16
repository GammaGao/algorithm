/* ����������Ϊn����������ϲ������λ��
 * ʱ�临�Ӷȣ�O(logn)
 * ˼·���ϲ���������λ��һ��������λ��֮���������ľ�ֵ����������������eg:1,3,5,7��2,4,6,8��λ���ֱ�Ϊ4��5����Ȼ�ϲ��������λ��
 *		ֻ���ܳ���������3,5��2,4�䡣������λ��λ4��3, ��������������λ��Ϊ(4+3)/2.0=3.5
 */
#include <iostream>
using namespace std;

static int error;
int max(int a, int b);
int min(int a, int b);
double median(int a[], int b[], int n)
{
	if (a == NULL || b == NULL || n == 0){
		error = -1;
		return error;
	}
	if (n == 1)
		return (a[0] + b[0]) / 2.0;

	int ai = 0, bi = 0;
	int aj = n - 1, bj = n - 1;
	int mida, midb;
	double result = 0;

	while (ai != aj-1 && bi != bj-1){
		mida = (ai + aj) / 2;
		midb = (bi + bj) / 2;
		if (n % 2){
			if (a[mida] == b[midb])
				return a[mida];
			else if(a[mida] > b[midb]){
				aj = mida; //�´αȽ϶���mida�ұߵ���
				bi = n - 1 - mida;
			}
			else{
				bj = midb;
				ai = n - 1 - midb;
			}
		}
		else{
			if (a[mida] <= b[midb]){
				ai = mida;
				bj = n - 1 - mida;
			}
			else{
				bi = midb;
				aj = n - 1 - midb;
			}
		}
	}
	return (max(a[ai], b[bi]) + min(a[aj], b[bj])) / 2.0;
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

int main()
{
	/* ��������1, nΪ���� */
	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8, 10}; 
	cout << median(a, b, sizeof(a)/sizeof(int)) << endl;

	/* ��������2, nΪż�� */
	int a1[] = {2, 3, 5, 10, 11, 12};
	int b1[] = {2, 4, 6, 8, 14, 200};
	cout << median(a1, b1, sizeof(a1) / sizeof(int)) << endl;

	/* ��������3, nΪ1 */
	int a2[] = { 1 };
	int b2[] = { 3 };
	cout << median(a2, b2, sizeof(a2) / sizeof(int)) << endl;

	/* ��������4, ���Ϸ����� */
	int b3[] = { 1, 2, 3 };
	cout << median(NULL, b, 1) << endl;

	/* ��������4�� ��һ��������Ԫ�ؾ�С�ڵ��ڵڶ��� */
	int a4[] = {1, 3, 4, 5, 7, 11, 13};
	int b4[] = {13, 14, 15, 16, 100, 101, 200};
	cout << median(a4, b4, sizeof(a4) / sizeof(int)) << endl;

	/* ��������5����һ��������Ԫ�ؾ�С�ڵڶ��� */
	int a5[] = { 1, 3, 4, 5, 7, 11, 13};
	int b5[] = { 14, 14, 15, 16, 100, 101, 200 };
	cout << median(a5, b5, sizeof(a5) / sizeof(int)) << endl;

	/* ��������6�� nΪż���ҵ�һ��������λ�����ڵڶ��� */
	int a6[] = {2, 5, 6, 7, 8, 10};
	int b6[] = {1, 3, 4, 9, 10, 100};
	cout << median(a6, b6, sizeof(a6) / sizeof(int)) << endl;

	/* ��������7�� nΪ�����ҵ�һ��������λ��С���ڵڶ��� */
	int a7[] = { 2, 5, 6, 7, 20, 21 , 23};
	int b7[] = { 1, 3, 4, 9, 10, 100 , 101};
	cout << median(a7, b7, sizeof(a7) / sizeof(int)) << endl;

	/* ��������8 nΪ�����ҵ�һ��������λ�����ڵڶ���*/
	int a8[] = { 2, 5, 6, 7, 8, 10, 23 };
	int b8[] = { 1, 3, 4, 7, 10, 100, 101 };
	cout << median(a8, b8, sizeof(a8) / sizeof(int)) << endl;
	system("pause");
}