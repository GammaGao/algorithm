/* 题目：已知随机数rand(), 以概率p产生0，以概率1-p产生1，现在要求设计一个新的随机函数RandN(), 
 *		 以等概率产生1-n之间的数。
 * 思路：首先这个rand()概率函数是假定存在的，
 * TIME：2015-4-28
 */

/* 等概率产生0-1
 * 0、1实际上是二进制数，那么使用rand()产生两个0的概率是
 */
int Rand()
{
	int i = 2;
	//00:p^2
	//01:p(1-p)
	//10:(1-p)p
	//11:(1-p)^2
	int n = 2*rand()+rand(); //转换成进制数
	if(n == 1) //p(1-p)
		return 0;
	else if(n == 2) //(1-p)p
		return 1;
}

/* 实现2 */
int Rand()
{
	int n1 = rand();
	int n2 = rand();
	if(n1 == 0 && n2 == 1)
		return 0;
	else if(n1 == 1 && n2 == 0)
		return 1;
}

/* 等概率产生1-n之间的数 */
int RandN(int n)
{
	int k = log2l(n)+1; //n的二进制位数
	int res = 0;
	for(int i = 0; i < k; ++)
		res = (res << i) + rand();
		
	if(res < n) //丢掉大于n的数, 重新产生数
		RandN();
	return res + 1;
}