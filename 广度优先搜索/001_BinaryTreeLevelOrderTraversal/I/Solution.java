package exam;

import java.util.LinkedList;
import java.util.Queue;

/**�������Ĳ��������������������������ġ�
 * 		8
 *     / \
 *    6  10
 *   / \ / \
 *  5  7 9 11
 *  �����Ϊ8,6,10,5,7,9,11
 *  �����Ҫ�ֲ�������磺
 *  8
 *  6,10
 *  5,7,9,11
 *  �͸���ҲһЩ���ο�II
 * @author ShaoCheng
 * @version 1.0 2015-12-6
 */
public class Solution {
	public static void levelOrder(TreeNode root) {
		if(root == null)
			return;
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		while(!q.isEmpty()) {
			TreeNode curr = q.poll();
			System.out.println(curr.val);
			if(curr.left != null)
				q.add(curr.left);
			if(curr.right != null)
				q.add(curr.right);
		}
	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	public TreeNode(int val) {
		// TODO Auto-generated constructor stub
		this.val = val;
	}
}
