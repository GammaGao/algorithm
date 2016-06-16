package leetcode;

/**Range Sum Query - Immutable
 * Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * @author ShaoCheng
 * @version 1.0 2015-12-17
 */

public class NumArray {
	private int[] sum;
	private int length;
    public NumArray(int[] nums) {
        length = nums.length;
        sum = new int[length+1];
        sum[0] = 0;
        for(int i = 0; i < length; i++) {
        	sum[i+1] = sum[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
    	if(i < 0 || j >= length)
    		return -1;
    	return sum[j+1] - sum[i];
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);