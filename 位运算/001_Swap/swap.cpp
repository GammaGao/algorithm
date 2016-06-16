#include <iostream>

using namespace std;

/* 不使用第三个变量交换 */
void swap(int *a, int *b)
{
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}

int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << a << "," << b << endl;
}
