package exam;

/**Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * For example:
 * Given array A = [2,3,1,1,4]
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * @author ShaoCheng
 * @version 1.1 2015-12-14
 */

/* time complexity depends on the value of the array.
 * Is not linear.
 */
public class Solution {
    public int jump(int[] nums) {
    	if(nums == null || nums.length < 2)
    		return 0; //do not move, step is 0.
    	
    	int l = 0;
    	int r = nums[0];
    	int step = 1;
    	while(l <= r) {
    		if(r >= nums.length-1) //reach the goal
    			return step;
    		int max = l + nums[l]; //the position can be reached in this round
    		for(; l <= r; l++) { //find the furtherest
    			if(nums[l]+l > max)
    				max = nums[l]+l;
    		}
    		if (max >= r) { //next round
    			l = r;
    			r = max;
    			step++;
    		}
    	}
    	return step;
    }
}