package leetcode;

import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Solution sl = new Solution();
		int[] a = {1, 2, 3, 4, 5, 6, 7, 8};
		int[] b = sl.circleMove(a, 9);
		System.out.println(Arrays.toString(b));
	}
}
