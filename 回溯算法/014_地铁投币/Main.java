package exam;

/**����Ͷ�����⣺1,5,10���ֱ��֡���������������Ͷ��NԪ�����ж�����Ͷ�ҷ�ʽ��
 * ˵����5,1,1��1,5,1��1,1,5�����ַ�ʽ����ͬ��
 * @version 1.0 2015-12-1
 * @author ShaoCheng
 * @see ����֮��������--��ΰ��
 */
/*
 * ��ʵ���Ͼ���һ���ݹ�����������Ŀ������5��1,1��1,5,1��1,1,5�����ַ�ʽ��������ȥ�ظ���
 * ��������
 */
public class Main {
	public static void main(String[] args){
		int[] a = {1, 5, 10};
		int n = combination(a, 10, 0, 0);
		System.out.print(n);
	}
	
	static int combination(int[] a, int target, int money, int n){
		if(a == null)
			return 0;
		for(int i =0; i < a.length; i++){
			money += a[i];
			if(money == target)
				return ++n;
			else if(money < target){
				n = combination(a, target, money, n);
				money -= a[i];
			}
			else{
				return n;
			}
		}
		return n;
	}
}
