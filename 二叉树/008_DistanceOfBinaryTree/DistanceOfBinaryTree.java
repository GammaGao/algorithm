package java_exam;

/**
 * 题目：求二叉树的两个节点之间最远的距离。
 * @author ShaoCheng
 * @version 1.0 2015-9-28
 */
/*
 * 计算一个二叉树的最大距离有两个情况:
 *	情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
 *	情况B: 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者。
 *	只需要计算这两个情况的路径距离，并取其大者，就是该二叉树的最大距离。
 */
public class DistanceOfBinaryTree {
	public static void main(String[] args){
		//			0
		//		   / \
		//        1   2
		//       / \  / \
		//      3  4 5   6
		//     /      \
		//    7        8
		TreeNode p0 = new TreeNode(0);
		TreeNode p1 = new TreeNode(1);
		TreeNode p2 = new TreeNode(2);
		TreeNode p3 = new TreeNode(3);
		TreeNode p4 = new TreeNode(4);
		TreeNode p5 = new TreeNode(5);
		TreeNode p6 = new TreeNode(6);
		TreeNode p7 = new TreeNode(7);
		TreeNode p8 = new TreeNode(8);
		p0.left = p1;
		p0.right = p2;
		p1.left = p3;
		p1.right = p4;
//		p2.left = p5;
//		p2.right = p6;
		p3.left = p7;
//		p5.right = p8;
		
		Result res = new Result();
		maxDistance(p0, res);
		System.out.println(res.maxDistance + " " + res.maxHeight);
	}
	
	public static void maxDistance(TreeNode root, Result res){
		if(root == null)
			return;
		
		Result lhs = new Result();
		Result rhs = new Result();
		maxDistance(root.left, lhs); //左子树的最大高度及最远距离
		maxDistance(root.right, rhs); //右子树的最大高度及最远距离
		res.maxHeight = Math.max(lhs.maxHeight, rhs.maxHeight) + 1;
		res.maxDistance = Math.max(Math.max(lhs.maxDistance, rhs.maxDistance), lhs.maxHeight + rhs.maxHeight + 2);
	}
	
	private static class Result{
		private int maxDistance = 0;
		private int maxHeight = -1;
	}
	
	private static class TreeNode{
		private int val;
		private TreeNode left;
		private TreeNode right;
		TreeNode(int val){
			this.val = val;
		}
	}

}
