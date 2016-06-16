package leetcode;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextLine()){
			String s = cin.nextLine();
			List<String> res = permute(s);
			for(int i = 0; i < res.size(); i++) {
				System.out.println(res.get(i));
			}
		}
		cin.close();
	}
	
	public static List<String> permute(String s){
		char[] str = s.toCharArray();
		List<String> result = new ArrayList<>();
		List<List<Character>> res = _permute(str, 0, str.length-1);
		for(int i = 0; i < res.size(); i++) {
			List<Character> tt = res.get(i);
			StringBuilder ss = new StringBuilder();
			for(Character c : tt) {
				ss.append(c);
			}
			result.add(ss.toString());
		}
		Collections.sort(result);
		return result;
	}
	
	private static List<List<Character>> _permute(char[] str, int start, int end) {
		List<Character> list = new ArrayList<>();
		List<List<Character>> res = new ArrayList<>();
		if(start > end)
			return res;
		if(start == end) {
			for(int i = 0; i <= end; i++) {
				list.add(str[i]);
			}
			res.add(list);
		}
		for(int i = start; i <= end; i++) {
			char temp = str[start];
			str[start] = str[i];
			str[i] = temp;
			res.addAll(_permute(str, start+1, end));
			
			temp = str[start];
			str[start] = str[i];
			str[i] = temp;
		}
		return res;
	}
}
