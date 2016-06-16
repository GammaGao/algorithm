package java_exam;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * �������ֽ�
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
	 * �ݹ�ʵ�������ӷֽ�
	 * @param res ��ŷֽ������������
	 * @param n ����������
	 */
	public static void primeFactor(ArrayList<Integer> res, int n){
		if(n <= 1)
			return;
		for(int i = 2; i <= n; i++){
			if(n % i == 0){
				n /= i;
				res.add(i);
				primeFactor(res, n);
				break; //�ɹ��ֽ������
			}
		}
	}
	
	/**
	 * ѭ��ʵ��
	 * @param res ��ŷֽ������������
	 * @param n ����������
	 */
	public static void primeFactorLoop(ArrayList<Integer> res, int n){
		if(n <= 1)
			return;
		for(int i = 2; i <= n; i++){ //����������2��ʼ��
			if(n % i == 0){ //�ҵ���������
				n /= i;
				res.add(i);
			}
			//����ǰ��n�ܷ�������Ѿ��ҵ�����������������
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
