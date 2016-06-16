package leetcode;

import java.util.Arrays;

/**题目：Implement Trie (Prefix Tree)字典树(前缀树)
 * Implement a trie with insert, search, and startsWith methods.
 * Note:
 *		You may assume that all inputs are consist of lowercase letters a-z.
 * @author ShaoCheng
 * @version 1.0 2015-10-14
 * @see leetcode
 */

/* 字典树：除根节点外，所有其他节点均只存放一个字符；从根节点到某一节点经过的字符连接起来，为该节点对应的字符串；
 * 		每个节点的所有子节点包含的字符都不相同。
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

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
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

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode t = root;
        for(int i = 0; i < word.length(); i++){
        	char c = word.charAt(i);
        	if(t.node[c - 'a'] != null){
        		t = t.node[c - 'a'];
        		continue;
        	}
        	else
        		return false;
        }
        return t.isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode t = root;
        for(int i = 0; i < prefix.length(); i++){
        	char c = prefix.charAt(i);
        	if(t.node[c - 'a'] != null){
        		t = t.node[c - 'a'];
        		continue;
        	}
        	else
        		return false;
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");