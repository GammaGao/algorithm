/**@TITLE:Minimum Window Substring(��С�Ӵ�����)
 * 		Given a string S and a string T, find the minimum window in S which will 
 * 		contain all the characters in T in complexity O(n).
 *		For example,
 *		S = "ADOBECODEBANC"
 *		T = "ABC"
 *		Minimum window is "BANC".
 * Note:
 *		If there is no such window in S that covers all characters(���У���ʹ�����ظ�Ԫ��) in T, return 
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

/**@˼·���ù�ϣ���ҵ����а���T���ַ����Ӵ����Ӵ��п��ܰ��������ظ�Ԫ�أ���"ADOEABBFGHCCBA"/"ABC"��
 * 		����һ�ҵ���ȫ����"ABC"���Ӵ�"ADOEABBFGHC"ʱ����Ȼ����������̵Ĵ��ڣ������������ڡ�����
 * 		����Ϊ"ABBFGHC"�� ����һ�����ڵĻ����ϼ����������п����и��̴��ڡ�������С�Ĵ��ڡ�
 * @���ܣ�ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)
 */
public class Solution {
    public String minWindow(String s, String t) {
    	if(s.length() < 1 || t.length() < 1)
    		return "";
        String res = ""; //Ĭ��Ϊ�մ�
        char[] needFind = new char[256]; //all is zero
        int[] IsFinded = new int[256]; //all is false
        
        for(int i = 0; i < t.length(); i++){
        	needFind[t.charAt(i)]++; //T������������ϣӳ�䣬 ��ֵֵΪT�ж�ӦԪ�ظ���
        }
        
        int start = 0, end = 0; //��ʼ����ָ��
        int count = 0; //��¼��s�����ҵ�����t���ĳ���
        int minLength = Integer.MAX_VALUE; //Ĭ�ϳ���
        for(; end < s.length(); end++){ //βָ���ƶ�
        	char curr = s.charAt(end);
        	if(needFind[curr] == 0) //s���еĵ�ǰλ�õ��ַ�����t����
        		continue;
        	//��s����ĳһ�ַ��������ڻ����t�и��ַ�����ʱ��count��Ӧ�ü���
    		if(IsFinded[curr] < needFind[curr]){
    			count++;
    		}
    		IsFinded[curr]++;//��¼�����Ѿ��ҵ���Ԫ�أ���ֵΪ�����
    		if(count == t.length()){ //�ҵ�һ��������ȫ������t�������ַ�
    			while(start < end){ //��������
    				curr = s.charAt(start);
    				if(needFind[curr] == 0){//���������в���t�е��ַ�
    					start++;
    					continue;
    				}
    				//IsFinded��needFind����Ĳ��־Ϳ��Ա�ɾ��
    				if(IsFinded[curr] > needFind[curr]){
    					start++;
    					IsFinded[curr]--;
    				}
    				else//����������������
    					break;
    			}
        		if(end + 1 - start < minLength){//��¼��С����
        			res = s.substring(start, end+1);
        			minLength = end + 1 - start;
        		}
    		}
        }
        
        return res;
    }
}
