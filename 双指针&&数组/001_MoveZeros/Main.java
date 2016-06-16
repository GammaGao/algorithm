package leetcode;

public class Main {
	public static void main(String[] args){
		Solution sl = new Solution();
//		int[] nums = {0, 1, 0, 3, 12};
//		int[] nums = {0, 1};
//		int[] nums = {1, 0};
		int[] nums = {0, 100, 0, 1, 0, 0};
		sl.moveZeroes(nums);
		for(int n : nums)
			System.out.println(n);
	}
}
