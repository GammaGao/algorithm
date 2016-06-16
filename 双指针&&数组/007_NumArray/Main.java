package leetcode;

public class Main {
	public static void main(String[] args) {
		int[] nums = {-2, 0, 3, -5, 2, -1};
		NumArray sl = new NumArray(nums);
		System.out.println(sl.sumRange(0, 2));
		System.out.println(sl.sumRange(2, 5));
		System.out.println(sl.sumRange(0, 5));
	}
}
