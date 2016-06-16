package java_exam;

import java.util.Arrays;

/**
 * ��Ŀ������ַ�������'0'-'9'��'A'-'Z'��'a'-'z'��ɣ�ʵ��Ҫ�����е������ַ�������ǰ�桢Сд��ĸ�����м䡢��д��ĸ���ں���
 * ʱ�临�Ӷȣ�����O(nlogn)����������o(n)
 * �ռ临�Ӷȣ�����O(1)������O(n)
 * @author ShaoCheng
 * @version 1.0 2015-9-24
 */
/*��Ȼ��Ŀ��Ҳû��Ҫ���м��������
 * �㷨˼·����������������ַ������Ȼ�ǰ�ASCII������ģ�����Сд��ĸ��ASCII���ڴ�д��ĸ����
 * ���������˼·�ǣ��ȴ�Сд��ĸ������Ȼ������������ٻ��ء�
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
//		Arrays.sort(array); //����
		countSort(array);   //�������� 
		for(int i = 0; i < array.length; i++){
			if(array[i] >= 'A' && array[i] <= 'Z')
				array[i] += 32;
			else if(array[i] >= 'a' && array[i] <= 'z')
				array[i] -= 32;
		}
		return array;
	}
	
	/* ���������㷨 */
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
