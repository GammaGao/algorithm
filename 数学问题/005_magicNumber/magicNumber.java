package java_exam;

import java.util.ArrayList;

public class Main {
	public static void main(String[] arqs) {
		ArrayList<Integer> res = MagicNum2(); //�㷨��
		
		for(int i = 0; i < res.size(); i++) {
			System.out.println(res.get(i));
		}
	}
	
	static int MAX_VALUE = 1000000000; //10����
	
	//�㷨��
	public static ArrayList<Integer> MagicNum2() {
		ArrayList<Integer> res = new ArrayList<>();
		
		for(int i = 1; i < MAX_VALUE; i++) {
			//����ƽ��������������������һ������ȫ6�η���
			int n = (int) Math.pow(i, 6);
			if(n <= MAX_VALUE)
				res.add(n);
			else
				break;
		}
		return res;
	}

	//�㷨һ
	public static ArrayList<Integer> MagicNum1(){
		ArrayList<Integer> res = new ArrayList<>();
		for(int i = 1;; i++){
			int sq = (int) Math.pow(i, 2);
			if(sq  > MAX_VALUE)
				break;
			for(int j = i; j >= 1; j--){
				if(Math.pow(j, 3) == sq){
					res.add(sq);
					System.out.println(sq);
				}
			}
		}
		return res;
	}
}