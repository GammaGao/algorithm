package leetcode;

/**����һ�Ŷ����������������¹��ܣ�ÿһ���ڵ㣬���������ڵĲ������������еļ������õĺ���С�Ķ���������
 * @author ShaoCheng
 * @version 1.0 2015-11-2
 * TODO Ŀǰ����ʱ���ؼ������õ���Сֵ����û�з�������������޸ġ�
 */

/*[1, 2, 3]
 * ����������ʽ��
 * 1         2          3
 *  \       / \        /
 *   2     1   3      2
 *    \              /
 *     3            1
 * ��һ�֣�1*1+2*2+3*3=14���ڶ��֣�2*1+(1+3)*2=10 �����֣�3*1+2*2+1*3=10
 * ����СֵΪ10������Ϊ�ڶ��ֻ�����־���
 */
class TreeNode{
	int val;
	TreeNode left, right;
	public TreeNode(int val) {
		this.val = val;
	}
}

public class Main {
	public static void main(String[] args){
		int[] a = new int[]{1, 2, 3, 4, 5};
		TreeNode root = null;
		int res = MinWeightBST(a, root, 0, a.length-1, 1);
		System.out.println(res);
	}
	
	public static int  MinWeightBST(int[] a, TreeNode root, int start, int end, int level){
		if(start > end)
			return 0;
		else if(start == end){
			root = new TreeNode(a[start]);
			return a[start]*level;
		}
		int res = Integer.MAX_VALUE, min = 0, index = start;
		for(int i = start; i <= end; i++){
			root = new TreeNode(a[i]);
			int left = MinWeightBST(a, root.left, start, i-1, level+1);
			int right = MinWeightBST(a, root.right, i+1, end, level+1);
			min = root.val * level + left + right;
			if(res > min){
				index = i;
				res = min;
			}
		}
		
		root = new TreeNode(a[index]);
		MinWeightBST(a, root.left, start, index-1, level+1);
		MinWeightBST(a, root.right, index+1, end, level+1);
		return res;
	}
}