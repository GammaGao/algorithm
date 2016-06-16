package java_exam;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 有几种纸币面值1, 5, 10, 20, 50, 100元，假设每种面值的纸币无限，用它们组合成N元。找出所有的组合数。
 * @author ShaoCheng
 * @version 1.1 2015-9-19
 */
public class Solution {
	/**
	 * @param N 输入的总和N
	 * @return 所有的组合数
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
    	coins = new int[]{1, 5, 10, 20, 100, 50}; //如果乱序，应先排序
    	Arrays.sort(coins);
	}
    private int[] coins;
}