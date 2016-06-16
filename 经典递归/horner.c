/*
 * ����ʽA(x) = a[n]*x^n + a[n-1]*x^(n-1)+...+ a[1]*x^1 + a[0],ֱ�Ӽ���ʱ��Ч�ʲ�����
 * Horner'ruler����A(x) = (...(((a[n]*x + a[n-1])*x + a[n-2])*x + a[n-3])*x+...+ a[1])*x + a[0]
 * Horner'rulerʹ����ʽ��ֵ����˷���������
 */
#include <stdio.h>
//#define DEBUG

/*
 * ���ɹ���ݹ��㷨
 * a[n]��ʾ����ʽϵ����i��ʾ�ݹ������x��ʾ����ʽ���ĵ������ֵ��n��ʾ����ʽ��ߴ���
 * ע�⣺ϵ��Ϊ0ʱ��Ҳ����ʡ��
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
