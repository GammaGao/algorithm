package exam;

/**地铁投币问题：1,5,10三种币种。现在想往地铁中投币N元，问有多少种投币方式。
 * 说明：5,1,1和1,5,1和1,1,5这三种方式均不同。
 * @version 1.0 2015-12-1
 * @author ShaoCheng
 * @see 汽车之家面试题--任伟航
 */
/*
 * 这实际上就是一道递归深搜索的题目。由于5，1,1和1,5,1和1,1,5这三种方式。故无需去重复。
 * 回溯深搜
 */
public class Main {
	public static void main(String[] args){
		int[] a = {1, 5, 10};
		int n = combination(a, 10, 0, 0);
		System.out.print(n);
	}
	
	static int combination(int[] a, int target, int money, int n){
		if(a == null)
			return 0;
		for(int i =0; i < a.length; i++){
			money += a[i];
			if(money == target)
				return ++n;
			else if(money < target){
				n = combination(a, target, money, n);
				money -= a[i];
			}
			else{
				return n;
			}
		}
		return n;
	}
}
