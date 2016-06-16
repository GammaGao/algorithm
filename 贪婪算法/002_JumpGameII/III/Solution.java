package exam;

/* time complexity must be O(n) */
public class Solution {
	public int jump(int[] nums) {
	    int maximum = 0;
	    int nextMaximum = 0;
	    int count = 0;

	    for (int i = 0; i < nums.length-1; i++) {
	        nextMaximum = Math.max(nextMaximum, nums[i]+i);
	        if (i == maximum) {
	            count ++;
	            if (nextMaximum >= nums.length-1) {
	                return count;
	            }
	            maximum = nextMaximum;
	        }
	    }
	    return count;
	}
}
