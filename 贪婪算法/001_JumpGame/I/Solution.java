package exam;

/**Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 * @author ShaoCheng
 * @version 1.0 2015-12-6
 */
/* 递归思路,时间复杂度比较差，依赖于每个点的值
 */
public class Solution {
    public boolean canJump(int[] nums) {
    	return nums.length == 0 ? false : _canJump(nums, 0);
    }
    
    public boolean _canJump(int[] nums, int index) {
    	boolean res = false;
    	if(index >= nums.length-1)
    		return true;
    	for(int i = nums[index]; i >= 1; i--) {
    		res = _canJump(nums, index+i);
    		if(res)
    			return res;
    	}
    	return res;
    }
}