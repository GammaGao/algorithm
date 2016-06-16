package exam;

public class Main {
	public static void main(String[] args) {
		int[] nums = {1,2,3,2,2,2,5,4,2};
		Solution sl = new Solution();
		int res = sl.majorityElement(nums);
		System.out.println(res);
	}
}
