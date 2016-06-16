package exam;

/**Wildcard Matching
 * Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 * @author ShaoCheng
 * @version 1.0 2015-12-15
 */

/* 递归实现，效率确实差 */
public class Solution {
	static int count = 0;
    public boolean isMatch(String s, String p) {
        return CoreMatch(s, 0, p, 0);
    }
    
    public boolean CoreMatch(String s, int indexS, String p, int indexP) {
    	if(indexS == s.length() && indexP == p.length())
    		return true;
    	if(indexS != s.length() && indexP == p.length())
    		return false;
    	if(indexS == s.length() && indexP != p.length())
    		return false;
    	if(s.charAt(indexS) == p.charAt(indexP) || p.charAt(indexP) == '?')
    		return CoreMatch(s, indexS+1, p, indexP+1);
    	else if(p.charAt(indexP) == '*') {
    		System.out.println(count++);
    		return CoreMatch(s, indexS+1, p, indexP+1)// *只匹配一个字符
    				|| CoreMatch(s, indexS+1, p, indexP) //把目标串指针移动，相当于匹配了一个，indexP没变
    				|| CoreMatch(s, indexS, p, indexP + 1); //*匹配空字符
    	}
    	else
    		return false;
    }
}