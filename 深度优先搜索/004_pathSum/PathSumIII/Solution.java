package leetcode;

/**二叉树路径加权和
 * 给定一棵二叉树，二叉树权值为0-9，得出所有根节点到叶节点的路径和。如下图的二叉树，路径和n=137+15=152
 * 	 1   
 *	/ \   
 * 3   5 
 *  \
 *   7
 * @author ShaoCheng
 * @version 1.0 2015-11-6
 * @see leetcode
 */

//二叉树定义
class Node {
    int value;
    Node left;
    Node right;
    Node(int x) { value = x; }
};

public class Solution {
    public int sumNumbers(Node root) { 
    	return _subNumber(root, 0);
    }
    
    public int _subNumber(Node root, int sum) {
    	if(root.left == null && root.right == null)
    		return sum*10 + root.value;
    	if(root.left != null && root.right != null)
    		return _subNumber(root.left, sum*10+root.value) + _subNumber(root.right, sum*10+root.value);
    	else if(root.left != null)
    		return _subNumber(root.left, sum*10 + root.value);
    	else
    		return _subNumber(root.right, sum*10 + root.value);
    }
};
