/* 求两个长度为n的排序数组合并后的中位数
 * 时间复杂度：O(logn)
 * 思路：合并后数组中位数一定在两中位数之间两个数的均值（包含这两个）。eg:1,3,5,7和2,4,6,8中位数分别为4和5，显然合并后的两中位数
 *		只可能出现在数字3,5和2,4间。又其中位数位4和3, 故最终两数组中位数为(4+3)/2.0=3.5
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
				aj = mida; //下次比较丢掉mida右边的数
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
	/* 测试用例1, n为奇数 */
	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8, 10}; 
	cout << median(a, b, sizeof(a)/sizeof(int)) << endl;

	/* 测试用例2, n为偶数 */
	int a1[] = {2, 3, 5, 10, 11, 12};
	int b1[] = {2, 4, 6, 8, 14, 200};
	cout << median(a1, b1, sizeof(a1) / sizeof(int)) << endl;

	/* 测试用例3, n为1 */
	int a2[] = { 1 };
	int b2[] = { 3 };
	cout << median(a2, b2, sizeof(a2) / sizeof(int)) << endl;

	/* 测试用例4, 不合法输入 */
	int b3[] = { 1, 2, 3 };
	cout << median(NULL, b, 1) << endl;

	/* 测试用例4， 第一个数组中元素均小于等于第二个 */
	int a4[] = {1, 3, 4, 5, 7, 11, 13};
	int b4[] = {13, 14, 15, 16, 100, 101, 200};
	cout << median(a4, b4, sizeof(a4) / sizeof(int)) << endl;

	/* 测试用例5，第一个数组中元素均小于第二个 */
	int a5[] = { 1, 3, 4, 5, 7, 11, 13};
	int b5[] = { 14, 14, 15, 16, 100, 101, 200 };
	cout << median(a5, b5, sizeof(a5) / sizeof(int)) << endl;

	/* 测试用例6， n为偶数且第一个数组中位数等于第二个 */
	int a6[] = {2, 5, 6, 7, 8, 10};
	int b6[] = {1, 3, 4, 9, 10, 100};
	cout << median(a6, b6, sizeof(a6) / sizeof(int)) << endl;

	/* 测试用例7， n为奇数且第一个数组中位数小于于第二个 */
	int a7[] = { 2, 5, 6, 7, 20, 21 , 23};
	int b7[] = { 1, 3, 4, 9, 10, 100 , 101};
	cout << median(a7, b7, sizeof(a7) / sizeof(int)) << endl;

	/* 测试用例8 n为奇数且第一个数组中位数等于第二个*/
	int a8[] = { 2, 5, 6, 7, 8, 10, 23 };
	int b8[] = { 1, 3, 4, 7, 10, 100, 101 };
	cout << median(a8, b8, sizeof(a8) / sizeof(int)) << endl;
	system("pause");
}