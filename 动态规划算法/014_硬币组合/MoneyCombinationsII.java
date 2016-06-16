package java_exam;

import java.util.Arrays;
import java.util.Scanner;

/**
 * �м���ֽ����ֵ1, 5, 10, 20, 50, 100Ԫ������ÿ����ֵ��ֽ�����ޣ���������ϳ�NԪ���ҳ����е��������
 * @author ShaoCheng
 * @version 1.1 2015-9-19
 */
public class Solution {
	/**
	 * @param N ������ܺ�N
	 * @return ���е������
	 */
    public long getNumberOfCombinations(int N) {
    	long sum = 0;
    	return getNumberOfCombinations(N, sum, 0);
    }
    
    public long getNumberOfCombinations(int N, long sum, int start){
    	long count = 0;
    	for(int i = start; i < coins.length; i++){
    		sum += coins[i];
    		if(sum == N){
    			count++;
    			break;
    		}
    		if(sum < N){
    			count += getNumberOfCombinations(N, sum, i);
    			sum -= coins[i];
    		}
    		else
    			break;
    	}
		return count;
    }
    
    public static void main(String[] args){
    	Solution sl = new Solution();
    	Scanner scanner = new Scanner(System.in);
    	int N = scanner.nextInt();
    	long res = sl.getNumberOfCombinations(N);
    	System.out.println(res);
    	scanner.close();
    }
    
    public Solution() {
		// TODO Auto-generated constructor stub
    	coins = new int[]{1, 5, 10, 20, 100, 50}; //�������Ӧ������
    	Arrays.sort(coins);
	}
    private int[] coins;
}