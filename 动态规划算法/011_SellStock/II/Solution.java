package leetcode;

/**Best Time to Buy and Sell Stock II
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * @author ShaoCheng
 * @version 1.1 2015-10-18
 * @see leetcode 贪婪算法
 */
/* 贪婪思路：每一天股票涨了，都交易一次，这样收益最大化
 */
public class Solution {
	public int maxProfit(int[] prices) {
	    int profit = 0;
	    for (int i = 1; i < prices.length; i++) {
	        int profitToday = prices[i] - prices[i - 1];
	        profit += profitToday > 0 ? profitToday : 0;
	    }
	    return profit;
	}
}