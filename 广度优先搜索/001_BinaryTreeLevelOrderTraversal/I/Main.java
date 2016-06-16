package exam;

public class Main {
	public static void main(String[] args) {
		/*		8
		 *     / \
		 *    6  10
		 *   / \ / \
		 *  5  7 9 11
		 */
		TreeNode p0 = new TreeNode(8);
		TreeNode p1 = new TreeNode(6);
		TreeNode p2 = new TreeNode(10);
		TreeNode p3 = new TreeNode(5);
		TreeNode p4 = new TreeNode(7);
		TreeNode p5 = new TreeNode(9);
		TreeNode p6 = new TreeNode(11);
		p0.left = p1;
		p0.right = p2;
		p1.left = p3;
		p1.right = p4;
		p2.left = p5;
		p2.right = p6;
		Solution.levelOrder(p0);
	}
}
