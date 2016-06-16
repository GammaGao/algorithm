package leetcode;

/**创建一颗二叉搜索树满足如下功能：每一个节点，乘以它所在的层数，他们所有的计算所得的和最小的二叉搜索树
 * @author ShaoCheng
 * @version 1.0 2015-11-2
 * TODO 目前代码时返回计算所得的最小值，而没有返回这颗树，待修改。
 */

/*[1, 2, 3]
 * 树有三种形式：
 * 1         2          3
 *  \       / \        /
 *   2     1   3      2
 *    \              /
 *     3            1
 * 第一种：1*1+2*2+3*3=14；第二种：2*1+(1+3)*2=10 第三种：3*1+2*2+1*3=10
 * 故最小值为10，树形为第二种或第三种均可
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