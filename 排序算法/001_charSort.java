package java_exam;

import java.util.Arrays;

/**
 * 题目假设给字符数组由'0'-'9'、'A'-'Z'、'a'-'z'组成，实现要求将所有的数字字符排在最前面、小写字母排在中间、大写字母排在后面
 * 时间复杂度：快排O(nlogn)、计数排序o(n)
 * 空间复杂度：快排O(1)、计数O(n)
 * @author ShaoCheng
 * @version 1.0 2015-9-24
 */
/*当然题目中也没有要求中间是排序的
 * 算法思路：正常情况对上述字符排序必然是按ASCII码排序的，由于小写字母的ASCII大于大写字母，故
 * 下述代码的思路是：先大小写字母互换，然后再排序，最后再换回。
 */
public class Main {
	public static void main(String[] args){
		char[] array = new char[]{'9', '0', 'Z', 'y', 'B', 'b', 'l', 'Z', 'z'};
		//char [] array = new char[]{'0'};
		char[] res = sort(array);
		System.out.println(res);
	}
	
	public static char[] sort(char[] array){
		if(array == null)
			return null;
		for(int i = 0; i < array.length; i++){
			if(array[i] >= 'A' && array[i] <= 'Z')
				array[i] += 32;
			else if(array[i] >= 'a' && array[i] <= 'z')
				array[i] -= 32;
		}
//		Arrays.sort(array); //快排
		countSort(array);   //计数排序 
		for(int i = 0; i < array.length; i++){
			if(array[i] >= 'A' && array[i] <= 'Z')
				array[i] += 32;
			else if(array[i] >= 'a' && array[i] <= 'z')
				array[i] -= 32;
		}
		return array;
	}
	
	/* 计数排序算法 */
	public static void countSort(char[] array){
		char[] count = new char['z' - '0' + 1];
		for(char c : array){
			count[c - '0']++;
		}
		
		int k = 0;
		for(int i = 0; i < 'z' - '0' + 1; i++){
			for(int j = 0; j < count[i]; j++){
				array[k++] = (char) (i + '0');
			}
		}
	}
}
