package leetcode;

/**Valid Anagram(Í¬¹¹´Ê)
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * @author ShaoCheng
 * @version 1.0 2015-10-18
 */
public class Solution {
    public boolean isAnagram(String s, String t) {
        int[] hashTable = new int[26];
        for(int i = 0; i < hashTable.length; i++)
        	hashTable[i] = 0;
        for(int i = 0; i < s.length(); i++)
        	hashTable[s.charAt(i) - 'a']++;
        for(int i = 0; i < t.length(); i++)
        	hashTable[t.charAt(i) - 'a']--;
        for(int i = 0; i < hashTable.length; i++){
        	if(hashTable[i] != 0)
        		return false;
        }
        return true;
    }
}