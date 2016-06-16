package java_exam;

/**
 * ��Ŀ����������������ڵ�֮����Զ�ľ��롣
 * @author ShaoCheng
 * @version 1.0 2015-9-28
 */
/*
 * ����һ�������������������������:
 *	���A: ·������������������ڵ㣬ͨ�����ڵ㣬�ٵ�������������ڵ㡣
 *	���B: ·�����������ڵ㣬��������������������������·����ȡ����ߡ�
 *	ֻ��Ҫ���������������·�����룬��ȡ����ߣ����Ǹö������������롣
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
		maxDistance(root.left, lhs); //�����������߶ȼ���Զ����
		maxDistance(root.right, rhs); //�����������߶ȼ���Զ����
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
