package java_exam;

import java.util.Scanner;

/**
 * �м���ֽ����ֵ1, 5, 10, 20, 50, 100Ԫ������ÿ����ֵ��ֽ�����ޣ���������ϳ�NԪ���ҳ����е��������
 * @author ShaoCheng
 * @version 1.0 2015-9-19
 */
public class Solution {
	/**
	 * @param N ������ܺ�N
	 * @return ���е������
	 */
    public long getNumberOfCombinations(int N) {
    	int coinKinds = coins.length;
    	int[][] dp = new int[coinKinds+1][N+1];
    	
    	for(int i = 0; i <= coinKinds; i++){ //��ʼ��
    		for(int j = 0; j <= N; ++j){
    			dp[i][j] = 0;
    		}
    	}
    	
    	for(int i = 0; i <= coinKinds; i++){
    		dp[i][0] = 1;//ǰi��ֽ����ϳ�0��ֻ��һ��������Ǹ�����Ϊ0
    	}
    	
    	for(int i = 1; i <= coinKinds; i++){
    		for(int j = 1; j <= N; j++){
    			dp[i][j] = 0;
    			for(int k = 0; k <= j / coins[i-1]; k++){
    				dp[i][j] += dp[i-1][j - k*coins[i-1]];
    			}
    		}
    	}
    	return dp[coinKinds][N];
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
    	coins = new int[]{1, 5, 10, 20, 50, 100};
	}
    private int[] coins;
}