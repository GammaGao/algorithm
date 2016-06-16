package leetcode;

/**数组循环左移动
 * 空间复杂度O(n)，时间复杂度O(n)
 * @author ShaoCheng
 */
public class Solution {
	/**
	 * @param a
	 * @param m 左移m位
	 * @return 循环左移后的数组
	 */
	int[] circleMove(int[] a, int m){
		int size = a.length;
		int n = m % size;
		int[] b = new int[size];
		for(int i = 0; i < size; i++){
			b[(i-n + size) % size] = a[i];
		}
		return b;
	}
}