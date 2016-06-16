package exam;

import java.util.*;
public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
		int n = 4;
		int[][] edges = {
				{1,0},
				{1,2},
				{1,3}
		}; 
	
//		int n = 6;
//		int[][] edges = {
//				{0,3},
//				{1,3},
//				{2,3},
//				{4,3},
//				{5,4}
//		};
		List<Integer> res = sl.findMinHeightTrees(n, edges);
		System.out.println(res.toString());
	}
}
