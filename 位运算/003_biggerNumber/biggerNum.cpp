/* ��Ŀ���ҳ��������нϴ��Ǹ���Ҫ�󲻵�ʹ��if-else�������Ƚ������
 * TIME��2015-5-1
 */
#include <iostream>
using namespace std;

/* ��תһλ */
int flip(int bit)
{
	return bit ^ 0x01;
}
/* ������deta�ķ���λ */
int sign(int deta)
{
	return (deta >> 31) & 0x01;
}

/* ʵ��1���ж���������ֵ�ķ���λ����
 * BUG���޷������ֵ��������ʱ�����
 */
int getMax1(int a, int b)
{
	int k = sign(a-b);
	int q = flip(k);
	//k==1,q==0��k==0, q==1
	return a*flip(k) + b*flip(q);
}

/* ʵ��2����α�����Ϊ�����ɵĴ����ж��ǽ��BUG�Ĺؼ�
 * ��������a > 0, b < 0 �� a < 0, b > 0������������ܻᷢ�����
 *		Ҳ��a��b���ʱ���ܻᷢ��������������һ�������������a��b��
 *		��ʱ���������жϴ�С�����ش������ֵ��
 */
int getMax2(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	//a��b�Ƿ����
	int is_diff_sign = sa^sb;

	//a��bͬ��ʱis_diff_signΪ0, k = flip(sc);
	//a��b���ʱis_diff_signΪ1��k = flip(sa);
	int k = flip(sa)*is_diff_sign + flip(sc)*flip(is_diff_sign);
	int q = flip(k);
	
	//k==1,q==0��k==0,q==1
	return a*k + b*q;
}

int main()
{
	int n1 = 1;
	int n2 = 200;
	cout << getMax1(n1, n2) << endl;
	cout << getMax2(n1, n2) << endl;

	int a = 2147483647; //int���ֵINT_MAX 
	int b = -15;
	int c = a - b;
	//cout << c << endl;
	cout << getMax1(a, b) << endl; //��������ű�ɸ�, ������
	cout << getMax2(a, b) << endl; //�������ȷ���
	system("pause");
}