/* 假设函数rand5()可以等概率地产生1-5之间的随机数, 求解产生rand7()等概率地产生1-7之间的随机数
 * 思路：因为rand5()可以产生1-5之间的数，rand5()-1产生的数就是五进制数0-4，要产生比它大的数就
 *		可以产生两位数进行截取。
 * 函数说明：srand()设置种子，rand()根据种子来产生随机数。要产生不同随机数，需要不同种子，可以时间为种子
 * TIME:2015-4-29
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* 假设rand5()等概率产生1-5。
 * 以下实现虽然产生的数是1-5但计算机是做不到等概率的
 */
int rand5()
{
	return rand()%5 + 1;
}

/* 等概率产生1-7之间的数
 */
int rand7()
{
	int n1, n2;
	int res = 0;

	//srand(time(0));
	n1 = rand5() - 1;
	n2 = rand5() - 1;

	//n1n2构成五进制两位数, 转换成十进制数
	//最小为0, 最大为4*5+4= 24
	res = n1 * 5 + n2;
	if (res < 21) //因为0-21之间的数%7， 重复的次数均为3次， 丢掉22、23、24会造成不等概率
		return res % 7 + 1;

	rand7();
}

int main()
{
	srand(time(0)); //设置rand()种子，否则默认rand()的种子为1

	for (int i = 0; i < 100; i++)
		cout << rand7() << " ";
	cout << endl;
	system("pause");
}