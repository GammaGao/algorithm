package exam;

public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
//		int[] gas = {2,3,1,1,6};
//		int[] cost = {3,4,1,2,3};
		
//		int[] gas = {6,0,1,3,2};
//		int[] cost = {4,5,2,5,5};
		
//		int[] gas = {1,2};
//		int[] cost = {2,1};
		
		int[] gas = {5,0,9,4,3,3,9,9,1,2};
		int[] cost = {6,7,5,9,5,8,7,1,10,5};
		int res = sl.canCompleteCircuit(gas, cost);
		System.out.println(res);
	}
}
