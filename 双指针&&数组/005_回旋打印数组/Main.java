package exam;

public class Main {
	public static void main(String[] args) {
		/* case1 */
//		int[][] a = {
//				{1}
//		};
		
		/* case2 */
//		int[][] a = {
//				{1,2},
//				{3,4}
//		};
	
		/* case3 */
//		int[][] a = {
//				{1,2,3},
//				{4,5,6},
//				{7,8,9}
//		};
		
		/* case4 */
//		int[][] a= {
//				{1,2,3,4},
//				{5,6,7,8},
//				{9,10,11,12},
//				{13,14,15,16}
//		};
		
		int[][] a = {
				{1,2},
				{3,4},
				{5,6},
				{7,8},
				{9,10}
		};
		
		//Solution.rotatingPrint(a);
		Solution.rotatingPrint(a, a.length, a[0].length, 0, 0);
	}
	

}
