/* 给定两个长度为m和n的排序数组，其它们的中位数，要求时间复杂度为O（log(m+n)） */
#include <iostream>
using namespace std;

static int error;

int max(int a, int b);
int min(int a, int b);
double MO2(int a, int b);
int MO3(int a, int b, int c);
double MO4(int a, int b, int c, int d);

double median(int a[], int m, int b[], int n);
double findMedian(int a[], int m, int b[], int n)
{
	if (m <= n){
		return median(a, m, b, n);
	}
	else
		return median(b, n, a, m);
}

double median(int a[], int m, int b[], int n)
{
	if (a == NULL || m <= 0 || b == NULL || n <= 0){
		error = -1;
		return error;
	}
	int ai = 0, bi = 0;
	int aj = m - 1, bj = n - 1;
	int mida, midb;

	mida = (ai + aj)/2;
	midb = (bi + bj)/2;
	/* m <= n*/
	if (m == 1){
		if (n == 1) //m==1, n==1
			return	MO2(a[0], b[0]);
		if (n % 2) //m==1, n为奇数
			return MO2(b[midb], MO3(a[0], b[midb-1], b[midb+1]));
		else		//m==1, n为偶数
			return MO3(a[0], b[midb], b[midb+1]);
	}
	if (m == 2){
		if (n % 2) //m == 2, n为奇数
			return MO3(b[midb], max(a[0], b[midb-1]), min(a[1], b[midb+1]));
		else
			return MO4(b[midb], b[midb+1], max(a[0], b[midb-1]), min(a[1], b[midb+2]));
	}

	if (a[mida] <= b[midb]) //注意
		return median(a + mida, m - mida, b, n - mida); //b长度大于a，b丢掉的长度与a保持一致
	else
		return median(a, m - mida, b + mida, n - mida);
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

/* 求两个数的中位数 */
double MO2(int a, int b)
{
	return (a + b) / 2.0;
}

/* 求三个数的中位数 */
int MO3(int a, int b, int c)
{
	//其和减去一个最大的数和一个最小的数
	return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

double MO4(int a, int b, int c, int d)
{	//其和减去一个最大和最小求均值
	return (a + b + c + d - max( a, max(b, max(c, d)) ) - min( a, min(b, min(c, d)) ))/2.0;
}

int main()
{
	int a1[] = { 2 };//换成1，10测试
	int b1[] = { 1, 2, 3 };
	cout << findMedian(a1, sizeof(a1) / sizeof(int), b1, sizeof(b1) / sizeof(int)) << endl;

	int a2[] = { 1 };//换成0,2,10测试
	int b2[] = { 1, 2 }; //长度为2
	cout << findMedian(a2, sizeof(a2) / sizeof(int), b2, sizeof(b2) / sizeof(int)) << endl;

	int a3[] = { 9 };//换成1, 10, 100分别测试
	int b3[] = { 2, 3, 10, 14, 17 }; //长度奇数>1
	cout << findMedian(a3, sizeof(a3) / sizeof(int), b3, sizeof(b3) / sizeof(int)) << endl;

	int a4[] = { 11 }; //10
	int b4[] = { 1, 2, 3, 4, 5, 10 }; //长度为偶数>2
	cout << findMedian(a4, sizeof(a4) / sizeof(int), b4, sizeof(b4) / sizeof(int)) << endl;

	//int a5[] = {12, 100}; //长度为2
	int a5[] = { 13, 100 }; //长度为2
	int b5[] = { 10, 11, 12, 100 }; //长度为偶数
	cout << findMedian(a5, sizeof(a5) / sizeof(int), b5, sizeof(b5) / sizeof(int)) << endl;

	int a6[] = { 13, 100 };
	int b6[] = { 10, 11, 12, 35, 100 }; //长度为奇数
	cout << findMedian(a6, sizeof(a6) / sizeof(int), b6, sizeof(b6) / sizeof(int)) << endl;

	int a7[] = { 1, 10, 11, 15, 17 }; //长度为奇数
	int b7[] = { 2, 11, 12, 14, 16, 18, 21, 100, 101 }; //长度为奇数
	cout << findMedian(a7, sizeof(a7) / sizeof(int), b7, sizeof(b7) / sizeof(int)) << endl;

	int a8[] = { 1, 10, 11, 15, 17 };//长度为奇数
	int b8[] = { 2, 11, 12, 14, 16, 18, 21, 100, 101, 102 }; //长度为偶数
	cout << findMedian(a8, sizeof(a8) / sizeof(int), b8, sizeof(b8) / sizeof(int)) << endl;

	int a9[] = {1, 10, 11, 13, 16, 21}; //长度为偶数
	int b9[] = {2, 11, 12, 14, 18, 18, 21, 100, 101, 102}; //长度为偶数
	cout << findMedian(a9, sizeof(a9) / sizeof(int), b9, sizeof(b9) / sizeof(int)) << endl;

	int a10[] = {1, 10, 11, 13, 17, 21}; //长度为偶数
	int b10[] = {2, 11, 12, 14, 18, 21, 100}; //长度为奇数
	cout << findMedian(a10, sizeof(a10) / sizeof(int), b10, sizeof(b10) / sizeof(int)) << endl;

	int a11[] = { 1, 10, 11, 13, 17, 21 }; //长度为偶数
	int b11[] = {22, 23, 25, 30, 31, 33 }; //长度相等
	cout << findMedian(a11, sizeof(a11) / sizeof(int), b11, sizeof(b11) / sizeof(int)) << endl;

	int a12[] = { 1, 10, 11, 13, 17, 21, 22}; //长度为奇数
	int b12[] = { 23, 23, 25, 30, 31, 33, 100}; //长度相等
	cout << findMedian(a12, sizeof(a12) / sizeof(int), b12, sizeof(b12) / sizeof(int)) << endl;
	system("pause");
}