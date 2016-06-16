/**@TITLE:Longest Substring Without Repeating Characters(最长的没有重复字符的子串)
 * 		Given a string, find the length of the longest substring without repeating
 * 		characters. For example, the longest substring without repeating letters for
 *  	"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
 *   	is "b", with the length of 1.
 * @AUTHOR:ShaoCheng
 * @TIME:2015-7-1
 * @FROM:leetcode
 * @TYPE:哈希、双指针
 */
package leetcode;

import java.util.HashMap;

/*
 * 思路：对于字符串abba，顺序扫描, start指向最长无重复字符子串的前一个位置，初值为-1，当扫描到第二个b（i=2）时，
 * 		查询哈希表发现b存在，故start被更新为1。
 */
class LongestSubstringWithoutRepeatingCharacters{
	public static int lengthOfLongestSubstring(String s) {
		//哈希表存放字符->位置索引值的映射, 当然你觉得小题大作的话，可以使用数组是完全可以的
		HashMap<Character, Integer> hmap = new HashMap<Character, Integer>();
		int maxLength = 0; //最大长度,实时更新
		int start = -1;
		for(int i = 0; i < s.length(); i++){
			if(!hmap.containsKey(s.charAt(i))) //在哈希表中查找
				hmap.put(s.charAt(i), i); //没找到时插入哈希表
			else{
				if(hmap.get(s.charAt(i)) > start) //若果找到之后，判断位置索引是否在start之后
					start = hmap.get(s.charAt(i));
				hmap.replace(s.charAt(i), i); //跟新位置索引值
			}
			if(i - start > maxLength) //实时更新
				maxLength = i-start;
		}
		return maxLength;
    }
	
	public static void main(String[] args) {
//		String s = new String("abcabcbb");
//		String s = new String("pwwekw");
//		String s = new String("bbbbbbbbb");
//		String s = new String("bcc");
		String s = new String("abba");
		int res = lengthOfLongestSubstring(s);
		System.out.println(res);
	}
}