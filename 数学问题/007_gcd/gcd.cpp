/* 题目：求两个正整数的最大公约数（Greatest Common Divisor, GCD）
 * TIME：2015-5-2
 */
#include <iostream>
using namespace std;

/* 公元300年左右，欧几里得《几何原本》中给出了高效的辗转相除法。
 * 原理：gcd(x, y), 取k=x/y, b=x%y,则a=y*k + b;因为a可以被gcd整除, 故b也可以被gcd整除
 *		有gcd(x, y) = gcd(y, x%y)。
 * 性能：递归处理这个问题非常简单，但是当数据很大时，如1100 100 210 001， 120 200 021求其
 *		gcd会造成很多次取模（除法运算），除法运算是非常昂贵的开销，将成为算法的性能瓶颈。
 */
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

/*  改进辗转相除法中的除法，用减法代替。
 *	原理：gcd(x,y)(x<=y), 取k = y, b=x-y,gcd(x,y)=gcd(y, x-y)
		（其中y >= x-y）或者gcd(x,y)=gcd(x-y, y)（y < x-y）
 * 性能：虽然改除法为减法，降低了除法的昂贵开销，但依然会有多次减法迭代。
 */
int gcd1(int a, int b)
{
	if(a < b)
		return gcd1(b, b-a);
	else
		return b ? gcd1(b, a-b) : a;
}

int main()
{
	cout << gcd(42000, 1505) << endl;
	cout << gcd(15, 20) << endl;

	cout << gcd1(42000, 1505) << endl;;
	cout << gcd1(15, 20) << endl;
	
	cout << gcd(300, 300) << endl;
	cout << gcd(300, 300) << endl;
}
