package exam;

/**
 * 其时间性能达不到理想的O(n)的时间复杂度
 * @author ShaoCheng
 * @version 1.0 2015-12-6
 */
public class Solution {
    public int majorityElement(int[] nums) {
        int start = 0;
        int end = nums.length-1;
        int middle = (start+end)/2;
        int index = PARTION(nums, 0, nums.length-1);
        while(index != middle) {
        	if(index > middle) {
        		end = index-1;
        		index = PARTION(nums, start, end);
        	}
        	else {
        		start = index + 1;
        		index = PARTION(nums, start, end);
        	}
        }
        return nums[index];
    }
    
    /* 来源于快速排序算法中的一个过程 */
    public int PARTION(int[] nums, int start, int end) {
    	int key = nums[start];
    	while(start < end) {
    		while(start < end && nums[end] >= key)
    			end--;
    		if(start < end)
    			nums[start++] = nums[end];
    		while(start < end && nums[start] <= key)
    			start++;
    		if(start < end)
    			nums[end--] = nums[start];
    	}
    	nums[start] = key;
    	return start;
    }
}