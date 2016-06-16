/**@TITLE: Repeated DNA Sequences
 *		All DNA is composed of a series of nucleotides abbreviated as A, C, G,
 *		and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful
 *		to identify repeated sequences within the DNA.
 *		Write a function to find all the 10-letter-long sequences (substrings) that
 *		occur more than once in a DNA molecule.
 *		For example,
 *		Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *		Return:
 *		["AAAAACCCCC", "CCCCCAAAAA"].
 * @TIME:2015-7-2
 * @FROM:leetcode
 * @TYPE:哈希表
 * @AUTHOR:PengSc
 */
package leetcode;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/* 思路：使用哈希表, 把每10个长度子串存放在哈希表中，当然最坏情况下，哈希表容量比较大
 * 改进：哈希表存放10个长度子串的编码，一节约空间，参考方法2中，对子串进行编码。
 */
public class RepeatedDNASequences {
	public static List<String> findRepeatedDnaSequences_1(String s){
//		List是interface， 只能实例化其子类的实现
		List<String> res = new ArrayList<String>();
		HashSet<String> strSet = new HashSet<String>(); //HashSet集合，只允许唯一元素
		HashMap<String, Integer> hmap = new HashMap<String, Integer>(); //哈希表
		for(int i = 0; i < s.length() - 9; i++){
			String sub = s.substring(i, i+10); //substring是不包括i+10位置的元素
			if(!hmap.containsKey(sub)) //在哈希中找不到
				hmap.put(sub, i);
			else{ //放入集合中，防止重复元素
				strSet.add(sub);
			}
		}
		for(String str: strSet)
			res.add(str);
		return res;
	}
	
	public List<String> findRepeatedDnaSequences(String s){
		List<String> res = new ArrayList<String>();
		HashSet<String> strSet = new HashSet<String>();
		HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
		for(int i = 0; i < s.length() - 9; i++){
			String sub = s.substring(i, i+10);
			int num = encode(sub); //把编码值放在哈希表中，而不是把子串放在哈希表中， 节约空间
			if(!hmap.containsKey(num))
				hmap.put(num, i);
			else{
				strSet.add(sub);
			}
		}
		for(String str:strSet){
			res.add(str);
		}
		return res;
	}
	
	/*
	 * DNA串是只由A/C/G/T组成，当成四进制, 如ACTG认为左边是低位，右边是高位，转换成0*4+1*4+3*4+2*4=24
	 */
	public int encode(String s){ //编码，把长度为10的DNA子串编码成唯一的数值
		int num = 0;
		int k = 1;
		for(int i = 0; i < s.length(); i++){
			switch(s.charAt(i)){
			case 'A': //0
				num += k*0;
				break;
			case 'C': //1
				num += k*1;
				break;
			case 'G': //2
				num += k*2;
				break;
			case 'T': //3
				num += k*3;
				break;
			}
			k *= 4;
		}
		return num;
	}
	
	public static void main(String[] args){
//		String s = new String("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
		String s = new String("AAAAAAAAAAAA");
		RepeatedDNASequences sl = new RepeatedDNASequences();
		List<String> res = sl.findRepeatedDnaSequences_1(s);
		for(int i = 0; i < res.size(); i++){
			System.out.println(res.get(i));
		}
	}
}
