package leetcode;

/**Excel Sheet Column Number
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 * @author ShaoCheng
 * @version 1.0 2015-10-17
 * @see leetcode
 */
/* 本质上是一个26进制 */
public class Solution {
    public int titleToNumber(String s) {
    	int res = 0;
    	for(int i = 0; i < s.length(); i++){
    		res = res*26 + s.charAt(i) - 'A' + 1;
    	}
        return res;
    }
}