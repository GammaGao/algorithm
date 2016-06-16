package leetcode;

/**Best Time to Buy and Sell Stock III
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note: 
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * @author ShaoCheng
 * @version 1.0 2015-10-18
 */
/* 找寻一个点j，将原来的price[0..n-1]分割为price[0..j]和price[j..n-1]，分别求两段的最大profit。
 * 进行优化：
 * 对于点j+1，求price[0..j+1]的最大profit时，很多工作是重复的，在求price[0..j]的最大profit中已经做过了。
 * 类似于Best Time to Buy and Sell Stock，可以在O(1)的时间从price[0..j]推出price[0..j+1]的最大profit。
 * 但是如何从price[j..n-1]推出price[j+1..n-1]？反过来思考，我们可以用O(1)的时间由price[j+1..n-1]推出price[j..n-1]。
 * 最终算法：
 * 数组l[i]记录了price[0..i]的最大profit，
 * 数组r[i]记录了price[i..n]的最大profit。
 * 已知l[i]，求l[i+1]是简单的，同样已知r[i]，求r[i-1]也很容易。
 * 最后，我们再用O(n)的时间找出最大的l[i]+r[i]，即为题目所求。
 */
public class Solution {
	/*时间复杂度O(n)*/
    public int maxProfit(int[] prices) {
    	if(prices.length == 0)
    		return 0;
    	
    	//从左至右求得最大利益矩阵
    	int[] profit1 = new int[prices.length];
    	int min = prices[0];
    	profit1[0] = 0;
        for(int i = 1; i < prices.length; i++){
        	min = prices[i] < min ? prices[i]: min;
        	if(prices[i]-min > profit1[i-1])
        		profit1[i] = prices[i]-min;
        	else
        		profit1[i] = profit1[i-1];
        }
        
        //从右至左求最大利益矩阵
        int[] profit2 = new int[prices.length];
        profit2[prices.length-1] = 0;
        int max = prices[prices.length-1];
        for(int i = prices.length-2; i >= 0; i--){
        	max = prices[i] > max ? prices[i]: max;
        	if(max - prices[i] > profit2[i+1])
        		profit2[i] = max - prices[i];
        	else
        		profit2[i] = profit2[i+1];
        }
        
        int res = 0;
        for(int i = 0; i < prices.length; i++){
        	if(profit1[i] + profit2[i] > res)
        		res = profit1[i] + profit2[i];
        }
        return res;
    }
}

/* 时间复杂度比较复杂，中间会有很多重复计算 */
class Solution2 {
    public int maxProfit(int[] prices) {
    	if(prices.length == 0)
    		return 0;
    	int res = 0;
        for(int i = 0; i < prices.length; i++){
            if(i >= 1 && prices[i] <= prices[i-1])
                continue;
        	for(int j = 1; j < i; j++){
        		int a = maxSellOneTime(prices, 0, j);
        		int b = maxSellOneTime(prices, j+1, i);
        		int c = maxSellOneTime(prices, 0, i);
        		int d = (a+b) > c ? (a+b) : c;
        		if(d > res)
        			res = d;
        	}
        }
        return res;
    }
    
    public int maxSellOneTime(int[] prices, int start, int end){
    	if(start >= end)
    		return 0;
    	int res = 0;
    	int lowest = prices[start];
    	for(int i = start + 1; i <= end; i++){
    		if(lowest > prices[i])
    			lowest = prices[i];
    		if(res < prices[i] - lowest)
    			res = prices[i] - lowest;
    	}
    	return res;
    }
}