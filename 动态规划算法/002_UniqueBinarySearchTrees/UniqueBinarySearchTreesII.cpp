/* TITLE: Given n, generate all structurally unique BST's (binary search trees)
 * that store values 1...n.
 * For example, Given n = 3, your program should return all 5 unique BST's shown below.
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 * 
 * TIME:2015-5-8
 * FROM:leetcode
 * TYPE:Dynamically Programming
 * TEST:VS2013
 */
#include <iostream>
#include <vector>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 以下是递归实现
 */
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		return generateTrees(1, n);
	}

private:
	vector<TreeNode*> generateTrees(int start, int end)
	{
		vector<TreeNode*> res;
		TreeNode *tree;
		vector<TreeNode*> ltree, rtree;
		if (start > end){
			res.push_back(NULL); //NULL也在res占一个元素位置
			return res;
		}
		else if (start == end){
			tree = new TreeNode(start);
			res.push_back(tree);
			return res;
		}
		else{
			for (int i = start; i <= end; i++){
				ltree = generateTrees(start, i-1); //所有左子树
				rtree = generateTrees(i+1, end); //所有右子树
				
				for (int j = 0; j < ltree.size(); j++){ //左右子树连接
					for (int k = 0; k < rtree.size(); k++){
						tree = new TreeNode(i); //每次都得重新创建新的root节点，否则导致最后结果被替换
						tree->left = ltree.at(j);
						tree->right = rtree.at(k);
						res.push_back(tree);
					}
				}
			}
			return res;
		}
	}
};

int main()
{
	Solution s;
//	int n = 0; //1, 其值为空
//	int n = 1; //1
//	int n = 2; //2
	int n = 3; //5 = 2 + 1 + 2
//	int n = 4; //14 = 5 + 2 + 2 + 5
//	int n = 5; //
	vector<TreeNode*> res = s.generateTrees(n);
	cout << res.size() << endl;
	system("pause");
}