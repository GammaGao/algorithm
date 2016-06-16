/* 题目：找出两个数中较大那个，要求不得使用if-else或其它比较运算符
 * TIME：2015-5-1
 */
#include <iostream>
using namespace std;

/* 反转一位 */
int flip(int bit)
{
	return bit ^ 0x01;
}
/* 测试数deta的符号位 */
int sign(int deta)
{
	return (deta >> 31) & 0x01;
}

/* 实现1：判断两个数差值的符号位即可
 * BUG：无法避免差值溢出，溢出时会出错
 */
int getMax1(int a, int b)
{
	int k = sign(a-b);
	int q = flip(k);
	//k==1,q==0或k==0, q==1
	return a*flip(k) + b*flip(q);
}

/* 实现2：如何避免因为溢出造成的错误判断是解决BUG的关键
 * 溢出情况：a > 0, b < 0 或 a < 0, b > 0这两种情况可能会发生溢出
 *		也即a、b异号时可能会发生溢出，其它情况一定不会溢出。当a、b异
 *		号时，很容易判断大小，不必处理溢出值。
 */
int getMax2(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	//a、b是否异号
	int is_diff_sign = sa^sb;

	//a、b同号时is_diff_sign为0, k = flip(sc);
	//a、b异号时is_diff_sign为1，k = flip(sa);
	int k = flip(sa)*is_diff_sign + flip(sc)*flip(is_diff_sign);
	int q = flip(k);
	
	//k==1,q==0或k==0,q==1
	return a*k + b*q;
}

int main()
{
	int n1 = 1;
	int n2 = 200;
	cout << getMax1(n1, n2) << endl;
	cout << getMax2(n1, n2) << endl;

	int a = 2147483647; //int最大值INT_MAX 
	int b = -15;
	int c = a - b;
	//cout << c << endl;
	cout << getMax1(a, b) << endl; //溢出，符号变成负, 错误结果
	cout << getMax2(a, b) << endl; //溢出，正确结果
	system("pause");
}