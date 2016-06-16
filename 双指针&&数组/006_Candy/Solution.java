package exam;


/**Candy
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 * @author ShaoCheng
 * @version 1.0 2015-12-17
 * @see 本题与发奖金算法雷同
 */
public class Solution {
    public int candy(int[] ratings) {
		int[] money = new int[ratings.length];
		int sum = 0;
		money[0] = 1;
		//从左至右处理右边，保证右边大的的人分得钱比左边相邻的人多
		for(int i = 1; i < ratings.length; i++){
			if(ratings[i] > ratings[i-1])
				money[i] = money[i-1] + 1;
			else
				money[i] = 1;
		}
//		System.out.println(Arrays.toString(money));
		
		//再从右至左保证左边相邻的人分得钱多
		for(int i = ratings.length-2; i >= 0; i--){
			if(ratings[i] > ratings[i+1])
				money[i] = Math.max(money[i], money[i+1] + 1);
		}
		
//		System.out.println(Arrays.toString(money));
		for(int i = 0; i < money.length; i++)
			sum += money[i];
		return sum;
    }
}