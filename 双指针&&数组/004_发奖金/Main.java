package leetcode;

public class Main {
	public static void main(String[] args){
		int[] a = {20, 32, 12, 32, 45, 11, 21, 41, 41, 33, 11, 11, 9, 8, 13};
		System.out.println(MoneyAlloc(a));
	}
	/**�Ѻ�������һ�κڿ������ɴ�����ȫ��˾����N�飬ÿ��һ�������ų�һ�ſ�ʼ����������������Ҫ������
	 * �������£���1wΪ��λ��ÿ�鶼���ٻᷢ1w�Ľ������⣬���һ���鷢���Լ��Ľ���û�и��ڱ��Լ��ɼ��͵���
	 * ���Ľ��𣬾ͻ᲻���⣬��Ϊ������֯�������ݳɼ���������Ҫ�����ٽ�����������������⡣
	 */
	public static int MoneyAlloc(int[] a){
		int[] money = new int[a.length];
		int sum = 0;
		money[0] = 1;
		//�������Ҵ����ұߣ���֤�ұߴ�ĵ��˷ֵ�Ǯ��������ڵ��˶�
		for(int i = 1; i < a.length; i++){
			if(a[i] > a[i-1])
				money[i] = money[i-1] + 1;
			else if(a[i] == a[i-1])
				money[i] = money[i-1];
			else
				money[i] = 1;
		}
		//�ٴ�������֤������ڵ��˷ֵ�Ǯ��
		for(int i = a.length-2; i >= 0; i--){
			if(a[i] > a[i+1])
				money[i] = Math.max(money[i], money[i+1] + 1);
			else if(a[i] == a[i+1])
				money[i] = money[i+1];
		}
		
//		System.out.println(Arrays.toString(money));
		for(int i = 0; i < money.length; i++)
			sum += money[i];
		return sum;
	}
}
