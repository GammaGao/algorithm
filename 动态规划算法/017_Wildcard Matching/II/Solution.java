package exam;

/**Wildcard Matching
 * Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 *'*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * @author ShaoCheng
 * @version 1.0 2015-12-17
 * @see Dynamic Program
 */

/* 动态规划实现，时间复杂度O(m*n)，空间复杂度O(m*n) */
public class Solution {
    public boolean isMatch(String s, String p) {
    	int m = s.length();
    	int n = p.length();
    	boolean[][] matrix = new boolean[m+1][n+1];
    	
    	matrix[0][0] = true; //s="" p="" is true
    	
    	//Handle cases like s="" p="****"
        for(int i=1;i<=n;i++)
        {
//            if(p.charAt(i-1) == '*')
//                matrix[0][i] = true;
//            else
//                break;
        	//concise to 1 line.
        	matrix[0][i] = matrix[0][i-1] && p.charAt(i-1) == '*';
        }
    	
    	for(int i = 1; i < m+1; i++) {
    		for(int j = 1; j < n+1; j++) {
    			char c = p.charAt(j-1); 
    			if(c != '*')
    				matrix[i][j] = matrix[i-1][j-1] //p和s中，当前位置的前一个字符匹配
    						&& (s.charAt(i-1) == c || c== '?');
    			else
    				matrix[i][j] = matrix[i][j-1] || matrix[i-1][j];
    		}
    	}
    	return matrix[m][n];
    }
}
