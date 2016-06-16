/**@TITLE:Longest Substring Without Repeating Characters(���û���ظ��ַ����Ӵ�)
 * 		Given a string, find the length of the longest substring without repeating
 * 		characters. For example, the longest substring without repeating letters for
 *  	"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
 *   	is "b", with the length of 1.
 * @AUTHOR:ShaoCheng
 * @TIME:2015-7-1
 * @FROM:leetcode
 * @TYPE:��ϣ��˫ָ��
 */
package leetcode;

import java.util.HashMap;

/*
 * ˼·�������ַ���abba��˳��ɨ��, startָ������ظ��ַ��Ӵ���ǰһ��λ�ã���ֵΪ-1����ɨ�赽�ڶ���b��i=2��ʱ��
 * 		��ѯ��ϣ����b���ڣ���start������Ϊ1��
 */
class LongestSubstringWithoutRepeatingCharacters{
	public static int lengthOfLongestSubstring(String s) {
		//��ϣ�����ַ�->λ������ֵ��ӳ��, ��Ȼ�����С������Ļ�������ʹ����������ȫ���Ե�
		HashMap<Character, Integer> hmap = new HashMap<Character, Integer>();
		int maxLength = 0; //��󳤶�,ʵʱ����
		int start = -1;
		for(int i = 0; i < s.length(); i++){
			if(!hmap.containsKey(s.charAt(i))) //�ڹ�ϣ���в���
				hmap.put(s.charAt(i), i); //û�ҵ�ʱ�����ϣ��
			else{
				if(hmap.get(s.charAt(i)) > start) //�����ҵ�֮���ж�λ�������Ƿ���start֮��
					start = hmap.get(s.charAt(i));
				hmap.replace(s.charAt(i), i); //����λ������ֵ
			}
			if(i - start > maxLength) //ʵʱ����
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