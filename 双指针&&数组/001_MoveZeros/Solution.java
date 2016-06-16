package leetcode;

/**Move Zeroes
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * @author ShaoCheng
 * @version 2015-10-16
 * @see leetcode
 */
public class Solution {
    public void moveZeroes(int[] nums) {
    	int i = 0;
        for(; i < nums.length; i++){
        	if(nums[i] == 0){
        		int j = i;
        		while(j < nums.length && nums[j] == 0)
        			j++;
        		if(j == nums.length)
        			break;
        		nums[i] = nums[j];
        		nums[j++] = 0;
        	}
        }
        for(; i < nums.length; i++)
        	nums[i] = 0;
    }
}
