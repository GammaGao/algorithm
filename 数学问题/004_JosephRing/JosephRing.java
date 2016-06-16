package java_exam;

/**
 * 约瑟夫环问题。这道题有三种解法，标记法，链表法，最牛叉的是数学方法。
 * 数学方法请百度！！！
 * @author ShaoCheng
 * @version 1.0 2015-9-26
 */
public class JosephRing {
	public static void main(String[] args){
		int res = josephRing(10, 3);
		System.out.println(res);
	}
	
	static int josephRing(int n, int m){
		int s = 0;
		for(int i = 2; i <= n; i++){
			s = (s + m)% i;
		}
		return s+1;
	}
}