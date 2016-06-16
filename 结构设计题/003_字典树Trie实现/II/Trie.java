package trie;

/**
 * 实现字典树（Trie树）:插入、查询、词频统计功能。
 * TODO 实现删除功能（很少使用）
 * @author ShaoCheng
 * @version 1.0 2015-9-15
 */

public class Trie {
	private int SIZE = 26;
	private TrieNode root; //字典树的根
 
	Trie() {//初始化 
		root=new TrieNode();
	}
 
	/* Trie树节点，每个节点只包含一个字符  */
	private class TrieNode {//字典树节点
		private int num;//有多少单词通过这个节点, 即节点字符出现的次数
		private TrieNode[] son;//所有的儿子节点
		private boolean isEnd;//是不是最后一个节点
		private char val; //节点的值
 
		TrieNode() {
			num = 1;
			son = new TrieNode[SIZE];
			isEnd = false;
		}
	}

	//在字典树中插入一个单词
	public void insert(String str) {
		if(str == null || str.length() == 0) {
			return;
		}
		
		TrieNode node = root;
		char[] letters = str.toCharArray();
		for(int i = 0, len = str.length(); i < len; i++) {
			int pos = letters[i] - 'a';
			if(node.son[pos] == null) {
				node.son[pos] = new TrieNode();
				node.son[pos].val = letters[i];
			}
			else {
				node.son[pos].num++;
			}
			node=node.son[pos];
		}
		node.isEnd = true;
	}
 
	//计算单词前缀的数量
	public int countPrefix(String prefix){
		if(prefix == null || prefix.length() == 0){
			return -1;
		}
		
		TrieNode node=root;
		char[] letters = prefix.toCharArray();
		for(int i = 0, len = prefix.length(); i < len; i++){
			int pos=letters[i] - 'a';
			if(node.son[pos] == null) {
				return 0;
			}
			else{
				node = node.son[pos];
			}
		}
		return node.num;
	}
 
	//在字典树中查找一个完全匹配的单词.
	public boolean has(String str){
		if(str==null||str.length()==0){
			return false;
		}
		TrieNode node=root;
		char[]letters=str.toCharArray();
		for(int i = 0,len = str.length(); i < len; i++){
			int pos = letters[i]-'a';
			if(node.son[pos] != null){
				node=node.son[pos];
			}
			else{
				return false;
			}
		}
		return node.isEnd;
	}
 
	//前序遍历字典树.
	public void preTraverse(TrieNode node){
		if(node != null){
			System.out.print(node.val+"-");
			for(TrieNode child: node.son){
				preTraverse(child);
			}
		}
	}
	 
	public TrieNode getRoot(){
		return this.root;
	}
 
	public static void main(String[]args){
		Trie tree = new Trie();
		String[]strs = {"banana","band","bee","absolute","acm",};
		String[] prefix = {"ba","b","band","abc",};
		for(String str : strs){
			tree.insert(str);
		}
		System.out.println(tree.has("abc"));
		System.out.println(tree.has("acm"));
		
		tree.preTraverse(tree.getRoot());
		System.out.println();
		
		//tree.printAllWords();
		for(String pre:prefix){
			int num = tree.countPrefix(pre);
			System.out.println(pre + " " + num);
		}
	}
}