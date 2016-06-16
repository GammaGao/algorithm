package leetcode;

import java.util.Arrays;

/**��Ŀ��Implement Trie (Prefix Tree)�ֵ���(ǰ׺��)
 * Implement a trie with insert, search, and startsWith methods.
 * Note:
 *		You may assume that all inputs are consist of lowercase letters a-z.
 * @author ShaoCheng
 * @version 1.0 2015-10-14
 * @see leetcode
 */

/* �ֵ����������ڵ��⣬���������ڵ��ֻ���һ���ַ����Ӹ��ڵ㵽ĳһ�ڵ㾭�����ַ�����������Ϊ�ýڵ��Ӧ���ַ�����
 * 		ÿ���ڵ�������ӽڵ�������ַ�������ͬ��
 */
class TrieNode {
    // Initialize your data structure here.
	public char val; //�ڵ��д�ŵ��ַ�
	public TrieNode[] node; //ָ���ӽڵ�
	public boolean isEnd; //�Ӹ��ڵ㵱ǰ�ڵ��Ƿ�������һ�����ʣ����ǽ���ǰ׺
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