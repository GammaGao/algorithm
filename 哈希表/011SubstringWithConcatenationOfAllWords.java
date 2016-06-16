/**@TITLE:Substring with Concatenation of All Words(所有单词串联的子串)
 * 		You are given a string, s, and a list of words, words, that are all of 
 * 		the same length. Find all starting indices of substring(s) in s that is a
 *  	concatenation of each word in words exactly once and without any intervening
 *  	characters.(所有的单词出现且只能出现一次，单词之间不能有其他无关字符)
 *		For example, given:
 *		s: "barfoothefoobarman"
 *		words: ["foo", "bar"]
 *		You should return the indices: [0,9].
 *		(order does not matter).
 * @TYPE:哈希表
 * @TIME:2015-7-18
 * @FROM:leetcode
 * @author ShaoCheng
 */
package leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;

/**思路：先把单词作哈希映射，然后扫描整个字符串。
 * 性能：最坏情况时间复杂度O(m*n), m为s串长度，n为单词个数
 */
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
    	List<Integer> res = new ArrayList<Integer>();
    	if(words.length <= 0 || words.length > s.length())
    		return res;
    	int wlen = words[0].length();
    	int n = words.length;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0; i < words.length; i++){
        	//map存放所有“单词->个数”的映射
        	map.put(words[i], map.containsKey(words[i]) ? map.get(words[i]) + 1 : 1);
//        	if(map.containsKey(words[i])) //上面代码更加简洁
//        		map.put(words[i], map.get(words[i]) + 1);
//        	else
//        		map.put(words[i], 1);
        }
        for(int i = 0; i < s.length()+1-wlen*n; i++){ //扫描主串
        	//set存放已经找到的单词->个数的映射
        	HashMap<String, Integer> set = new HashMap<String, Integer>();
        	int count = 0; //统计找到单词个数
        	for(int j = i; j <= s.length()-wlen; j += wlen){
            	String sub = s.substring(j, j+wlen);
            	if(map.containsKey(sub)){  //获取子串，看其是否在words数组中
            		if(!set.containsKey(sub))
            			set.put(sub, 1);
            		else if(set.get(sub) < map.get(sub)){ //存在，个数还没超
            			set.put(sub, set.get(sub) + 1);
            		}
            		else
            			break;
            		count++;
            	}
            	else
            		break;

            	if(count == n){
            		res.add(i);
            		break;
            	}
        	}
        }
        return res;
    }
}
