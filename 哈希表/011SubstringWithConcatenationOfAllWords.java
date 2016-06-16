/**@TITLE:Substring with Concatenation of All Words(���е��ʴ������Ӵ�)
 * 		You are given a string, s, and a list of words, words, that are all of 
 * 		the same length. Find all starting indices of substring(s) in s that is a
 *  	concatenation of each word in words exactly once and without any intervening
 *  	characters.(���еĵ��ʳ�����ֻ�ܳ���һ�Σ�����֮�䲻���������޹��ַ�)
 *		For example, given:
 *		s: "barfoothefoobarman"
 *		words: ["foo", "bar"]
 *		You should return the indices: [0,9].
 *		(order does not matter).
 * @TYPE:��ϣ��
 * @TIME:2015-7-18
 * @FROM:leetcode
 * @author ShaoCheng
 */
package leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;

/**˼·���Ȱѵ�������ϣӳ�䣬Ȼ��ɨ�������ַ�����
 * ���ܣ�����ʱ�临�Ӷ�O(m*n), mΪs�����ȣ�nΪ���ʸ���
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
        	//map������С�����->��������ӳ��
        	map.put(words[i], map.containsKey(words[i]) ? map.get(words[i]) + 1 : 1);
//        	if(map.containsKey(words[i])) //���������Ӽ��
//        		map.put(words[i], map.get(words[i]) + 1);
//        	else
//        		map.put(words[i], 1);
        }
        for(int i = 0; i < s.length()+1-wlen*n; i++){ //ɨ������
        	//set����Ѿ��ҵ��ĵ���->������ӳ��
        	HashMap<String, Integer> set = new HashMap<String, Integer>();
        	int count = 0; //ͳ���ҵ����ʸ���
        	for(int j = i; j <= s.length()-wlen; j += wlen){
            	String sub = s.substring(j, j+wlen);
            	if(map.containsKey(sub)){  //��ȡ�Ӵ��������Ƿ���words������
            		if(!set.containsKey(sub))
            			set.put(sub, 1);
            		else if(set.get(sub) < map.get(sub)){ //���ڣ�������û��
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
