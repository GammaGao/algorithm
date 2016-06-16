/*
 * 多项式A(x) = a[n]*x^n + a[n-1]*x^(n-1)+...+ a[1]*x^1 + a[0],直接计算时，效率并不高
 * Horner'ruler规则：A(x) = (...(((a[n]*x + a[n-1])*x + a[n-2])*x + a[n-3])*x+...+ a[1])*x + a[0]
 * Horner'ruler使多项式求值所需乘法次数最少
 */
#include <stdio.h>
//#define DEBUG

/*
 * 霍纳规则递归算法
 * a[n]表示多项式系数，i表示递归参数，x表示多项式在哪点计算其值，n表示多项式最高次数
 * 注意：系数为0时，也不能省略
 */
double horner(float *a, int i, float x, int n)
{
	double  result = 0;
	if(i > n){
		return 0;
	}
	result = horner(a, i+1, x, n) * x + a[i]; 
	
	#ifdef DEBUG
		printf("res:%f\n", result);
	#endif
	return result;
}
int main()
{
	float a[] = {1.70, 0, 2.3, 0.5};
	printf("%f\n", horner(a, 0, 2, sizeof(a)/sizeof(a[0]) - 1));
	return 0;
}
