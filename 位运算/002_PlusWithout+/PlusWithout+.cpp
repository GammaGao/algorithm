/* 题目：将两个数相加（减法可转换成加法）。不得使用+或其他算术运算符。
 * TIME：2015-5-4
 */
#include <iostream>
#include <bitset>
using namespace std;

/* 解法非常精妙，因为不能使用+和其他算术运算符，那么得深入加法原理
 * 只能用位运算来实现加法，两个数相加=（相加但不进位）+（只进位值）。
 * 例如以十进制运算演示，33+78 = 01+110（110为进位值） = 111（此时进位值为0）；
 * 同理二进制，1111+0110=1001(对应位相加，但不进位)+1100(产生的进位值)=00101+10000（
	产生的进位）=10101+0（进位为0）=21。逐步把进位消除。
 * 负数时，计算机只知道补码，与运算是全部是补码。
 */
class Solution{
public:
	int Add(int x, int y)
	{
		if (y == 0)
			return x;
		int sum = x ^ y; //x+y但不考虑进位
		int carry = (x & y) << 1; //单独计算进位值
		cout << bitset<32>(sum) << "," << bitset<32>(carry) << endl; //查看二进制（补码），计算机只会以补码的形式运算
		return Add(sum, carry);
	}
};

int main()
{
	Solution s;
	int sum = s.Add(-16, -7);
	cout << sum << endl;
	//cout <<bitset<32> (sum) << endl; //注意负数输出的是补码
	system("pause");
}