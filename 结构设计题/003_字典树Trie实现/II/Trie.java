package trie;

/**
 * ʵ���ֵ�����Trie����:���롢��ѯ����Ƶͳ�ƹ��ܡ�
 * TODO ʵ��ɾ�����ܣ�����ʹ�ã�
 * @author ShaoCheng
 * @version 1.0 2015-9-15
 */

public class Trie {
	private int SIZE = 26;
	private TrieNode root; //�ֵ����ĸ�
 
	Trie() {//��ʼ�� 
		root=new TrieNode();
	}
 
	/* Trie���ڵ㣬ÿ���ڵ�ֻ����һ���ַ�  */
	private class TrieNode {//�ֵ����ڵ�
		private int num;//�ж��ٵ���ͨ������ڵ�, ���ڵ��ַ����ֵĴ���
		private TrieNode[] son;//���еĶ��ӽڵ�
		private boolean isEnd;//�ǲ������һ���ڵ�
		private char val; //�ڵ��ֵ
 
		TrieNode() {
			num = 1;
			son = new TrieNode[SIZE];
			isEnd = false;
		}
	}

	//���ֵ����в���һ������
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
 
	//���㵥��ǰ׺������
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
 
	//���ֵ����в���һ����ȫƥ��ĵ���.
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
 
	//ǰ������ֵ���.
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