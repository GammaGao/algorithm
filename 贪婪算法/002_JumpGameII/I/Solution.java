package exam;

/**Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * For example:
 * Given array A = [2,3,1,1,4]
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * @author ShaoCheng
 * @version 1.0 2015-12-14
 */

/* Solve this problem recursively. But performance is not very well.
 * limit to the large of stack. 
 */
public class Solution {
    public int jump(int[] nums) {
        int steps = _jump(nums, nums.length-1, 0);
        return steps;
    }
    
    public int _jump(int[] nums, int end, int steps) {
    	if(end == 0)
    		return steps;
    	boolean reachable = false;
    	for(int i = 0; i < end && !reachable; i++) {
    		if(i+nums[i] >= end) {
    			steps = _jump(nums, i, steps + 1);
    			if(steps != 0)
    				reachable = true;
    		}
    	}
    	if(reachable)
    		return steps;
    	steps = 0;
    	return steps;
    }
}