package leetcode;

/**����ѭ�����ƶ�
 * �ռ临�Ӷ�O(n)��ʱ�临�Ӷ�O(n)
 * @author ShaoCheng
 */
public class Solution {
	/**
	 * @param a
	 * @param m ����mλ
	 * @return ѭ�����ƺ������
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