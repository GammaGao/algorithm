/**题目：给完全二叉树插入一个节点，插完后保证还是完全二叉树
 * @author ShaoCheng
 * @version 1.0 2015-9-24
 */

class TreeNode{
	int val;
	TreeNode left, right;
	TreeNode(int key){
		val = key;
	}
}

public class Main {
	public static void main(String[] args){
		TreeNode p1 = new TreeNode(1);
		TreeNode p2 = new TreeNode(2);
		TreeNode p3 = new TreeNode(3);
		TreeNode p4 = new TreeNode(4);
		p1.left = p2;
		p1.right = p3;
		p2.left = p4;
		
		TreeNode node = new TreeNode(100);
		TreeNode root = insertBinary(p1, node);
		printTree(root);
	}
	
	//中序遍历
	public static void printTree(TreeNode root){
		if(root == null)
			return;
		System.out.println(root.val);
		printTree(root.left);
		printTree(root.right);
	}

	public static TreeNode insertBinary(TreeNode root, TreeNode node){
		if(root == null)
			return node;
		else if(node == null)
			return root;
		if(root.left == null){
			root.left = node;
			return root;
		}
		else if(root.right == null){
			root.right = node;
			return root;
		}
		
		int lrh = 0;
		int rrh = 0;
		TreeNode pNode = root.left;
		while(pNode != null){
			lrh++;
			pNode = pNode.right;
		}
		
		pNode = root.right;
		while(pNode != null){
			rrh++;
			pNode = pNode.left;
		}
		
		if(lrh != rrh){
			insertBinary(root.right, node);
		}
		else
			insertBinary(root.left, node);
		return root;
	}
}
