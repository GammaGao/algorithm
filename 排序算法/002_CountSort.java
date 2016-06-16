package java_exam;

/**
 * ���������㷨���ʺ�Ԫ��ֵ�������ظ��϶���������������ľ�������ͨ��ͳ�ƴ�����������
 * 		����ڱȽ������㷨�����ܸ��ѡ������ó������ޣ�����Թ�˾Ա������������ȡ�
 * ���ܣ�ʱ�临�ӶȽ�O(n)���ռ临�Ӷ�O(n)��
 * @author ShaoCheng
 * @version 1.0 2015-9-17
 */
public class Main {
	/* �ǳ������ʵ�� */
	public static void countSort(int a[]){
		if(a == null)
			return;
		int max = a[0];
		for(int i = 1; i < a.length; i++){ //��ǰ�������ֵ
			if(max < a[i])
				max = a[i];
		}
		
		int[] count = new int[max+1];
		for(int i = 0; i < count.length; i++){ //��ʼ��
			count[i] = 0;
		}
		for(int i = 0; i < a.length; i++){ //ͳ��a�и���Ԫ�س��ֵĴ���
			count[a[i]]++;
		}
		int k = 0;
		for(int i = 0; i <= max; i++){
			for(int j = 0; j < count[i]; j++){
				//ֵi������a�г�����count[i]�Σ��ͽ�a[]����count[i]�Σ��൱�ڸ�����a[]����
				a[k++] = i;
			}
		}
	}
	
	/* ���㷨���۵�����ʵ�� */
	public static int[] countSort1(int a[]){
		if(a == null)
			return null;
		int max = a[0];
		for(int i = 1; i < a.length; i++){ //��ǰ�������ֵ
			if(max < a[i])
				max = a[i];
		}
		
		int[] count = new int[max+1];
		for(int i = 0; i < count.length; i++){ //��ʼ��
			count[i] = 0;
		}
		for(int i = 0; i < a.length; i++){ //ͳ��a�и���Ԫ�س��ֵĴ���
			count[a[i]]++;
		}
		for(int i = 1; i < count.length; i++){ //�ۼƴ���
			count[i] += count[i-1];
		}
		
		int[] b = new int[a.length];
		for(int i = a.length-1; i >= 0; i--){ //ͨ��ͳ�ƵĴ�������Ԫ��λ�� 
			b[count[a[i]] - 1] = a[i]; //ע��������0��ʼ
			count[a[i]]--; //��һ��Ϊ�˷�ֹ��ͬԪ�ز���ͬһλ��
		}
		return b;
	}
	
	public static void main(String[] args){
		int[] a = new int[]{6, 7, 8, 10, 6, 7, 6, 6, 16, 10};
		int[] b = countSort1(a);
		for(int v: b)
			System.out.println(v);
	}
}
