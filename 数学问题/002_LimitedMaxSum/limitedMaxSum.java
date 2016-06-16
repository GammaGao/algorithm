package java_exam;

/**����һ������arr������Ĵ�����ѡ������Ԫ��x,y�������ǵ����z=x+y������limit�����
 * ���в�����limit����Ϻ�������һ����
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
