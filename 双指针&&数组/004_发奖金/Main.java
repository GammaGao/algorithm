package leetcode;

public class Main {
	public static void main(String[] args){
		int[] a = {20, 32, 12, 32, 45, 11, 21, 41, 41, 33, 11, 11, 9, 8, 13};
		System.out.println(MoneyAlloc(a));
	}
	/**搜狐进行了一次黑客马拉松大赛，全公司共分N组，每组一个房间排成一排开始比赛，比赛结束后，要发奖金。
	 * 规则如下，以1w为单位，每组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组
	 * 发的奖金，就会不满意，作为比赛组织方，根据成绩计算至少要发多少奖金才能让所有组满意。
	 */
	public static int MoneyAlloc(int[] a){
		int[] money = new int[a.length];
		int sum = 0;
		money[0] = 1;
		//从左至右处理右边，保证右边大的的人分得钱比左边相邻的人多
		for(int i = 1; i < a.length; i++){
			if(a[i] > a[i-1])
				money[i] = money[i-1] + 1;
			else if(a[i] == a[i-1])
				money[i] = money[i-1];
			else
				money[i] = 1;
		}
		//再从右至左保证左边相邻的人分得钱多
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
