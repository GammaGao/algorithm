/* TITLE: Divide Two Integers 
 *		Divide two integers without using multiplication(乘号), division(除号) and mod operator(取模).
 *		If it is overflow, return MAX_INT.
 *
 * TIME:2015-5-16
 * FROM:leetcode
 * TYPE:binary search
 * AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

/* 使用二分查找算法来实现除法
 * 比如：17/5，5<<1 < 17 < 5<<2, 17-5<<1=7, 再对7作同样处理
 */
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return INT_MAX;
		if (dividend == 0)
			return 0;

		unsigned absDividend, absDivisor, res;
		bool positive = (dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0);
		absDividend = dividend >= 0 ? dividend : -dividend;
		absDivisor = divisor > 0 ? divisor : -divisor;
		res = __divide(absDividend, absDivisor);
		if (positive && res > INT_MAX) //正数越界， 发生在INT_MIN/(-1)
			return INT_MAX;
		return positive ? res : 0 - res;
	}

private:
	unsigned int __divide(unsigned dividend, unsigned divisor)
	{
		unsigned global_res = 0, local_res = 1;
		unsigned long long t1 = divisor;
		unsigned deta;
		deta = dividend;
		while (deta >= divisor){ //差值与divisor比较
			t1 <<= 1; //如果t1在INT_MAX/2~INT_MAX之间时，会INT_MAX越界
			if (t1 == deta){//如果可以直接整除
				local_res <<= 1;
				global_res += local_res;
				break;
			}
			else if (t1 > deta){ //eg:17/5, 5<<2时 25>17时
				deta -= (t1 >> 1);
				t1 = divisor;
				global_res += local_res;
				local_res = 1;
			}
			else
				local_res <<= 1;
		}
		return global_res;
	}
};

int main()
{
	Solution sl;
	//for (int i = 0; i < INT_MAX; i++)
	cout << sl.divide(INT_MIN, -1) << endl;
	cout << sl.divide(INT_MIN, 1) << endl;
	system("pause");
}