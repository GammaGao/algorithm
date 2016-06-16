package leetcode;

/**Majority Element(数组中某一元素个数超过当前数组的一半)
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * @author ShaoCheng
 * @version 1.0 2015-10-17
 * @see leetcode
 */
public class Solution {
    public int majorityElement(int[] nums) {
    	int count = 1;
    	int res = nums[0];
    	for(int i = 1; i < nums.length; i++){
    		if(count == 0){
    			res = nums[i];
    			count = 1;
    		}
    		else{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    			if(nums[i] == res)
    				count++;
    			else
    				count--;
    		}
    	}
		return res;
    }
}
