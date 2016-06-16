package exam;

public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
		int numCourses = 2;
		int[][] prerequisites = {
				{1,0},
				{0,1}
		};
		
//		int numCourses = 3;
//		int[][] prerequisites = {
//				{0,1},
//				{0,2},
//				{1,2}
//		};
		
		boolean res = sl.canFinish(numCourses, prerequisites);
		System.out.println(res);
	}
}
