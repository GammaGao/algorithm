package java_exam;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 质因数分解
 * @author ShaoCheng
 * @version 1.0 2015-9-22
 */
public class PrimeFactor {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		ArrayList<Integer> res = new ArrayList<>();
		ArrayList<Integer> res1 = new ArrayList<>();
		primeFactor(res, n);
		primeFactorLoop(res1, n);
		System.out.println(res);
		System.out.println(res1);
		scanner.close();
	}
	
	/**
	 * 递归实现质因子分解
	 * @param res 存放分解出来的质因子
	 * @param n 输入正整数
	 */
	public static void primeFactor(ArrayList<Integer> res, int n){
		if(n <= 1)
			return;
		for(int i = 2; i <= n; i++){
			if(n % i == 0){
				n /= i;
				res.add(i);
				primeFactor(res, n);
				break; //成功分解后跳出
			}
		}
	}
	
	/**
	 * 循环实现
	 * @param res 存放分解出来的质因子
	 * @param n 输入正整数
	 */
	public static void primeFactorLoop(ArrayList<Integer> res, int n){
		if(n <= 1)
			return;
		for(int i = 2; i <= n; i++){ //从质数因子2开始找
			if(n % i == 0){ //找到质数因子
				n /= i;
				res.add(i);
			}
			//看当前的n能否继续被已经找到的质因子整除殆尽
			for(int j = 0; j < res.size(); j++){
				int factor = res.get(j);
				if(n % factor != 0)
					break;
				n /= factor;
				res.add(factor);
			}
		}
	}
}
