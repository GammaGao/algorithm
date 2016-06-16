package leetcode;

/**题目：Add and Search Word - Data structure design
 * Design a data structure that supports the following two operations:
 * 		void addWord(word)
 *		bool search(word)
 *		search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 *		For example:
 *		addWord("bad")
 *		addWord("dad")
 *		addWord("mad")
 *		search("pad") -> false
 *		search("bad") -> true
 *		search(".ad") -> true
 *		search("b..") -> true
 *	Note:
 *		You may assume that all words are consist of lowercase letters a-z.
 * @author ShaoCheng
 * @version 1.0 2015-10-15
 * @see leetcode
 */
/*
 * 使用前缀树实现带通配符匹配的单词搜索
 */
class TrieNode {
    // Initialize your data structure here.
	public char val; //节点中存放的字符
	public TrieNode[] node; //指向子节点
	public boolean isEnd; //从根节点当前节点是否可以组成一个单词，还是仅是前缀
	public final static int Alpha = 26; //a-z
    public TrieNode() {
    	node = new TrieNode[26];
    	//Arrays.fill(node, null);
    	isEnd = false;
    }
}

public class WordDictionary {
	private TrieNode root;
	public WordDictionary() {
		root = new TrieNode();
	}

    // Adds a word into the data structure.
    public void addWord(String word) {
    	TrieNode t = root;
        for(int i = 0; i < word.length(); i++){
        	char c = word.charAt(i);
        	if(t.node[c - 'a'] != null){
            	if(i == word.length()-1)
            		t.node[c - 'a'].isEnd = true;
        		t = t.node[c - 'a'];
        		continue;
        	}
        	t.node[c - 'a'] = new TrieNode();
        	t.node[c - 'a'].val = c;
        	if(i == word.length()-1)
        		t.node[c - 'a'].isEnd = true;
        	t = t.node[c - 'a'];
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
    	return _search(word, root, 0);
    }
    
    private boolean _search(String word, TrieNode root, int index){
    	if(index == word.length() && root.isEnd)
    		return true;
    	else if(index >= word.length())
    		return false;
        for(int i = index; i < word.length(); i++){
        	char c = word.charAt(i);
        	if(c == '.'){ //通配符.
        		for(int j = 0; j < TrieNode.Alpha; j++){
        			boolean res = false;
        			if(root.node[j] != null)
        				 res = _search(word, root.node[j], i + 1); //只能回溯查找了
        			if (res)
        				return true;
        		}
        		return false;
        	}
        	else{
        		if(root.node[c - 'a'] == null){
        			return false;
        		}
        		root = root.node[c - 'a'];
        	}
        }
        return root.isEnd;
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");