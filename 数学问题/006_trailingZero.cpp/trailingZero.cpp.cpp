/* ��Ŀ��N�Ľ׳˷��ж��β����Trailing Zero(10100��2��β��0)
 * TIME:2015-4-30
 */
#include <iostream>
using namespace std;

/* ������
 * ˼·1���ȼ���׳ˣ�Ȼ������ÿλ�ϵ�0
 * ���� ��ʱ�临�Ӷ�O(!n)���������������
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

/* ˼·2��ÿ�����������Էֽ�������ĳ˻�,��10 = 2*5�� 100 = (2^2)*(5^2)
 *		0�Ĳ��������ڳ�����2*5����ȻҪ����׳˵�β��0�ĸ�����ֻ��Ҫ֪��2*5�ĸ�����
 *		�۲췢�֣��׳˷ֽ��2�ĸ������Ƕ���5�����ԣ�ʵ����0�ĸ���ʵ������5�ĸ�����
 * ���ܣ�ʱ�临�Ӷ�O(n), ���������
 */
/* ����n����5�����Ӹ��� */
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

/* ˼·3��ͬ2�� ֻ��ͳ��5�ķ�����ߡ�
 *		����1-n��5���ӡ�25�����ӡ�125������...������
 *		1-n֮���м���m�ı�����ֱ��n/m.
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
