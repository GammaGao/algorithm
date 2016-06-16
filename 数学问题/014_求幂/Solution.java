package exam;

public class Solution {
	/*ѭ��ʵ�֣���������ʱ�临�Ӷ�O(n)nΪָ���ĸ���
	 */
	int pow(int base, int n) {
		if(base == 0)
			return 0;
		int res = 1;
		for(int i = 0; i < n; i++)
			res *= base;
		return res;
	}
	
	/*����ʵ�֣��ݹ�
	 * ʱ�临�Ӷ�O(logn)
	 */
	int pow2(int base, int n) {
		if(base == 0)
			return 0;
		if(n == 1)
			return base;
		int res = pow(base, n>>1);
		res *= res;
		if((n & 0x01) != 0) //��������
			res *= base;
		return res;
	}
	
	/* 3^9������9ת��Ϊ������1001,��3^9(ָ��Ϊʮ����)=3^(0001+1000)(����ָ��Ϊ������)
	 * �ⷨ���ʱ�临�ӶȽ���ָ���е�1�ĸ����й�
	 */
	int pow4(int base, int n) {
		if(base == 0)
			return 0;
		if(n == 1)
			return base;
		int tmp = 1;
		int flag = 1;
		int res = 0;
		if((n & 1) != 0) //��������
			res = base;
		else //ż������
			res = 1;
		while(flag != 0) {
			if((n & flag) != 0) //�ж�ָ���������ж�Ӧ��λ�Ƿ�Ϊ1
				res *= tmp*tmp;
			flag <<= 1;
			tmp *= base;
		}
		return res;
	}
}