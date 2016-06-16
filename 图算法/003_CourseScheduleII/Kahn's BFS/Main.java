package exam;

import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
		
		int numCourses = 2;
		int[][] prerequisites = {
				{1, 0},
				{0, 1}
		};
		
//		int numCourses = 4;
//		int[][] prerequisites = {
//				{1,0},
//				{2,0},
//				{3,1},
//				{3,2}
//		};
		
		int[] res = sl.findOrder(numCourses, prerequisites);
		System.out.println(Arrays.toString(res));
	}
}
