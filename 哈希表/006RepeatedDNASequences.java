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
 * @TYPE:��ϣ��
 * @AUTHOR:PengSc
 */
package leetcode;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/* ˼·��ʹ�ù�ϣ��, ��ÿ10�������Ӵ�����ڹ�ϣ���У���Ȼ�����£���ϣ�������Ƚϴ�
 * �Ľ�����ϣ����10�������Ӵ��ı��룬һ��Լ�ռ䣬�ο�����2�У����Ӵ����б��롣
 */
public class RepeatedDNASequences {
	public static List<String> findRepeatedDnaSequences_1(String s){
//		List��interface�� ֻ��ʵ�����������ʵ��
		List<String> res = new ArrayList<String>();
		HashSet<String> strSet = new HashSet<String>(); //HashSet���ϣ�ֻ����ΨһԪ��
		HashMap<String, Integer> hmap = new HashMap<String, Integer>(); //��ϣ��
		for(int i = 0; i < s.length() - 9; i++){
			String sub = s.substring(i, i+10); //substring�ǲ�����i+10λ�õ�Ԫ��
			if(!hmap.containsKey(sub)) //�ڹ�ϣ���Ҳ���
				hmap.put(sub, i);
			else{ //���뼯���У���ֹ�ظ�Ԫ��
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
			int num = encode(sub); //�ѱ���ֵ���ڹ�ϣ���У������ǰ��Ӵ����ڹ�ϣ���У� ��Լ�ռ�
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
	 * DNA����ֻ��A/C/G/T��ɣ������Ľ���, ��ACTG��Ϊ����ǵ�λ���ұ��Ǹ�λ��ת����0*4+1*4+3*4+2*4=24
	 */
	public int encode(String s){ //���룬�ѳ���Ϊ10��DNA�Ӵ������Ψһ����ֵ
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
