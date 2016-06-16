package leetcode;

public class Main {
	public static void main(String[] args){
		Trie t = new Trie();
//		t.insert("abc");
//		System.out.println(t.search("abc"));
//		System.out.println(t.search("ab"));
//		t.insert("ab");
//		System.out.println(t.search("ab"));
//		t.insert("ab");
//		System.out.println(t.search("ab"));
//		System.out.println(t.search("lian"));
		
//		t.insert("a");
//		System.out.println(t.search("a")); //true
//		System.out.println(t.startsWith("a")); //true
		
		t.insert("ab");
		t.insert("a");
		System.out.println(t.search("a")); //true
		System.out.println(t.startsWith("a")); //true
	}
}
