package leetcode;

public class Main {
	public static void main(String[] args){
		WordDictionary sl = new WordDictionary();
//		sl.addWord("bad");
//		System.out.println(sl.search("bad"));
//		System.out.println(sl.search("ba."));
//		System.out.println(sl.search("b.."));
//		
//		sl.addWord("dad");
//		sl.addWord("mad");
//		System.out.println(sl.search("pad"));
//		System.out.println(sl.search("bad"));
//		System.out.println(sl.search(".ad"));
//		System.out.println(sl.search("b.."));
		
//		sl.addWord("a");
//		sl.addWord("a");
//		System.out.println(sl.search("."));
//		System.out.println(sl.search("a"));
//		System.out.println(sl.search("aa"));
//		System.out.println(sl.search("a"));
//		System.out.println(sl.search(".a"));
//		System.out.println(sl.search("a."));
		
		sl.addWord("at");
		sl.addWord("and");
		sl.addWord("an");
		sl.addWord("add");
		System.out.println(sl.search("a"));
		System.out.println(sl.search(".at"));
		sl.addWord("bat");
		System.out.println(sl.search(".at"));
		System.out.println(sl.search("an."));
	}
}
