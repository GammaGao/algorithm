/* TITLE: Divide Two Integers 
 *		Divide two integers without using multiplication(�˺�), division(����) and mod operator(ȡģ).
 *		If it is overflow, return MAX_INT.
 *
 * TIME:2015-5-16
 * FROM:leetcode
 * TYPE:binary search
 * AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

/* ʹ�ö��ֲ����㷨��ʵ�ֳ���
 * ���磺17/5��5<<1 < 17 < 5<<2, 17-5<<1=7, �ٶ�7��ͬ������
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
		if (positive && res > INT_MAX) //����Խ�磬 ������INT_MIN/(-1)
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
		while (deta >= divisor){ //��ֵ��divisor�Ƚ�
			t1 <<= 1; //���t1��INT_MAX/2~INT_MAX֮��ʱ����INT_MAXԽ��
			if (t1 == deta){//�������ֱ������
				local_res <<= 1;
				global_res += local_res;
				break;
			}
			else if (t1 > deta){ //eg:17/5, 5<<2ʱ 25>17ʱ
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