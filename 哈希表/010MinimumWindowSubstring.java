/**@TITLE:Minimum Window Substring(最小子串窗口)
 * 		Given a string S and a string T, find the minimum window in S which will 
 * 		contain all the characters in T in complexity O(n).
 *		For example,
 *		S = "ADOBECODEBANC"
 *		T = "ABC"
 *		Minimum window is "BANC".
 * Note:
 *		If there is no such window in S that covers all characters(所有，即使包括重复元素) in T, return 
 *		the empty string "".
 *		If there are multiple such windows, you are guaranteed that there will 
 *		always be only one unique minimum window in S.
 * @TYPE:hash table, double pointer
 * @TIME:2015-7-13
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
package leetcode;
import java.lang.String;

/**@思路：用哈希表找到所有包含T中字符的子串，子串中可能包含过多重复元素，如"ADOEABBFGHCCBA"/"ABC"，
 * 		当第一找到完全包含"ABC"的子串"ADOEABBFGHC"时，显然它并不是最短的窗口，必须缩减窗口。可以
 * 		缩减为"ABBFGHC"， 在上一个窗口的基础上继续，后续有可能有更短窗口。返回最小的窗口。
 * @性能：时间复杂度O(n), 空间复杂度O(1)
 */
public class Solution {
    public String minWindow(String s, String t) {
    	if(s.length() < 1 || t.length() < 1)
    		return "";
        String res = ""; //默认为空串
        char[] needFind = new char[256]; //all is zero
        int[] IsFinded = new int[256]; //all is false
        
        for(int i = 0; i < t.length(); i++){
        	needFind[t.charAt(i)]++; //T串用数组做哈希映射， 数值值为T中对应元素个数
        }
        
        int start = 0, end = 0; //起始索引指针
        int count = 0; //记录在s串中找到符合t串的长度
        int minLength = Integer.MAX_VALUE; //默认长度
        for(; end < s.length(); end++){ //尾指针移动
        	char curr = s.charAt(end);
        	if(needFind[curr] == 0) //s的中的当前位置的字符不在t串中
        		continue;
        	//当s串中某一字符个数等于或多于t中该字符个数时，count不应该计数
    		if(IsFinded[curr] < needFind[curr]){
    			count++;
    		}
    		IsFinded[curr]++;//记录所有已经找到的元素，数值为其个数
    		if(count == t.length()){ //找到一个窗口完全包含了t串所有字符
    			while(start < end){ //缩减窗口
    				curr = s.charAt(start);
    				if(needFind[curr] == 0){//跳过窗口中不在t中的字符
    					start++;
    					continue;
    				}
    				//IsFinded比needFind多出的部分就可以被删除
    				if(IsFinded[curr] > needFind[curr]){
    					start++;
    					IsFinded[curr]--;
    				}
    				else//不能再缩减窗口了
    					break;
    			}
        		if(end + 1 - start < minLength){//记录最小窗口
        			res = s.substring(start, end+1);
        			minLength = end + 1 - start;
        		}
    		}
        }
        
        return res;
    }
}
