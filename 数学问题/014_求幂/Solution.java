package exam;

public class Solution {
	/*循环实现，暴力方法时间复杂度O(n)n为指数的个数
	 */
	int pow(int base, int n) {
		if(base == 0)
			return 0;
		int res = 1;
		for(int i = 0; i < n; i++)
			res *= base;
		return res;
	}
	
	/*二分实现，递归
	 * 时间复杂度O(logn)
	 */
	int pow2(int base, int n) {
		if(base == 0)
			return 0;
		if(n == 1)
			return base;
		int res = pow(base, n>>1);
		res *= res;
		if((n & 0x01) != 0) //奇数次幂
			res *= base;
		return res;
	}
	
	/* 3^9将其中9转换为二进制1001,，3^9(指数为十进制)=3^(0001+1000)(其中指数为二进制)
	 * 解法很妙，时间复杂度仅与指数中的1的个数有关
	 */
	int pow4(int base, int n) {
		if(base == 0)
			return 0;
		if(n == 1)
			return base;
		int tmp = 1;
		int flag = 1;
		int res = 0;
		if((n & 1) != 0) //奇数次幂
			res = base;
		else //偶数次幂
			res = 1;
		while(flag != 0) {
			if((n & flag) != 0) //判断指数二进制中对应的位是否为1
				res *= tmp*tmp;
			flag <<= 1;
			tmp *= base;
		}
		return res;
	}
}