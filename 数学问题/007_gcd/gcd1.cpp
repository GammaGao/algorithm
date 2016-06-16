/* 题目：求两个正整数的最大公约数
 * TIME：2015-5-3
 */
#include <iostream>
using namespace std;

int gcd(int a, int b, int *common)
{
	if(a == b)
		return a;
	if(!(a&1) && !(b&1)){ //均为偶数
		*common *= 2;
		return gcd(a>>1, b>>1, common); //a、b均除2
	}
	if(a < b)
		gcd(a, b-a, common);
	else
		gcd(b, a-b, common);
}

/* 重载函数，求最大约数母函数
 * 原理：《九章算术》中”更相减损法“求两个正整数的最大公约数。
 * 		原语：“可半者半之，不可半者，副置分母、子之数，以少减多，更相减损，求其等也。以等数约之。” 
 * 解析：1.如果两个正整数都是偶数，则用2使之约半，直至不能约简。
 *		 2.用较大的数减去较小的数，再比较差值和较小的数。
 *		 3.重复上述过程，直到两个数相等, 最大公约数即等数*common（其中common为约去的2的积）。
 * 例子：gcd(42,30) = 2*gcd(21,30) = 2*gcd(21,9) = 2*gcd(9,12) = 2*gcd(9,3) = 2*gcd(3, 6) = 2*gcd(3,3)=2*3
 * 性能：时间复杂度O(log2(max(x,y)))
 */
int gcd(int a, int b)
{
	int common = 1; //约去的2的乘积
	int tmp = gcd(a, b, &common);
	return common * tmp;
}

int main()
{
	cout << gcd(42, 30) << endl;
	cout << gcd(17, 110) << endl;
}