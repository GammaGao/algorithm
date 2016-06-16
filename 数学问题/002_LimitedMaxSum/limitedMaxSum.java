package java_exam;

/**给定一个数组arr，随机的从里面选择两个元素x,y，求它们的组合z=x+y，给定limit，求出
 * 所有不大于limit的组合和中最大的一个。
 * @author ShaoCheng
 * @version 1.0 2015-9-19
 */
public class Solution {
    public int limitedMaxSum(int[] arr, int length, int limit) {
    	int max = Integer.MIN_VALUE;
    	for(int i = 0; i < arr.length; i++){
    		for(int j = 0; j < arr.length; j++){
    			int sum = arr[i] + arr[j];
    			if(sum <= limit && max < sum)
    				max = arr[i]+arr[j];
    		}
    	}
    	
    	return max;
    }
    public static void main(String[] args){
    	Solution sl = new Solution();
    	int[] arr = new int[]{2, 4, 6};
    	int res = sl.limitedMaxSum(arr, arr.length, 7);
    	System.out.println(res);
    }
}
