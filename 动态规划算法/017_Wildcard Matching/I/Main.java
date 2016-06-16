package exam;

public class Main {
	public static void main(String[] args) {
		Solution sl = new Solution();
		System.out.println(sl.isMatch("aa", "a"));
		System.out.println(sl.isMatch("aa", "aa"));
		System.out.println(sl.isMatch("aaa", "aa"));
		System.out.println(sl.isMatch("aaa", "*"));
		System.out.println(sl.isMatch("a", "?"));
		System.out.println(sl.isMatch("ab", "*?"));
		System.out.println(sl.isMatch("aab", "*b"));
		System.out.println(sl.isMatch("aab", "c*a*b"));
		System.out.println(sl.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b")); //递归实现效率太差
		System.out.println(sl.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabb", "a*******b"));
		System.out.println(sl.isMatch("aaabbbaabaaaaa", "a*******b"));
	}
}
