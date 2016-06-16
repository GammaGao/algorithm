/* 题目：N的阶乘法有多个尾随零Trailing Zero(10100有2个尾随0)
 * TIME:2015-4-30
 */
#include <iostream>
using namespace std;

/* 蛮力法
 * 思路1：先计算阶乘，然后再求每位上的0
 * 性能 ：时间复杂度O(!n)，大数极易溢出。
 */
int factorOfN_1(int n)
{
	int num = 0;
	unsigned long long res = 1;
	for (int i = 1; i <= n; i++){
		res *= i;
	}
	cout << res << endl;
	while (res%10 == 0){
		num++;
		res /= 10;
	}
	return num;
}

/* 思路2：每个整数都可以分解成素数的乘积,如10 = 2*5， 100 = (2^2)*(5^2)
 *		0的产生是由于出现了2*5，显然要计算阶乘的尾随0的个数，只需要知道2*5的个数。
 *		观察发现，阶乘分解后，2的个数总是多于5。所以，实际上0的个数实际上是5的个数。
 * 性能：时间复杂度O(n), 不会溢出。
 */
/* 数字n包含5的因子个数 */
int factorsOf5(int n)
{
	int num = 0;
	while (n % 5 == 0){
		num++;
		n /= 5;
	}
	return num;
}

int factorOfN_2(int n)
{
	int count = 0;
	while (n > 1){ //!n
		count += factorsOf5(n);
		n--;
	}
	return count;
}

/* 思路3：同2， 只是统计5的方法提高。
 *		计算1-n间5因子、25的因子、125的因子...个数。
 *		1-n之间有几个m的倍数，直接n/m.
 */
int factorOfN_3(int n)
{
	int num = 0;
	for (int i = 5; n / i > 0; i *= 5){
		num += n / i;
	}
	return num;
}

int main()
{
	cout << factorOfN_1(24) << endl;
	cout << factorOfN_2(24) << endl;
	cout << factorOfN_3(24) << endl;
	system("pause");
}
