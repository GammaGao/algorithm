package exam;

public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
//		int[] nums = {2,3,1,1,4};
		int[] nums = {5,9,3,2,1,0,2,3,3,1,0,0};
		int res = sl.jump(nums);
		System.out.println(res);
	}
}
