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
 * @see Greedy算法
 */

/* 分析：如果一个目标点可到达，意味着，前面所有点中必有索引为i的点，其i+val >= 目标点的索引,如果能把所有点i+val值中最大记录下。
 * 贪婪的思路
 */
public class Solution {
    public boolean canJump(int[] nums) {
    	int reachable = 0;
        for(int i = 0; i < nums.length; i++) { //遍历每个点，判断其可达性
        	if(reachable < i) //如果点i不可达，后面的点必定不可达
        		return false;
        	reachable = reachable > i + nums[i] ? reachable : i + nums[i];
        }
        return true;
    }
}
