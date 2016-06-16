package leetcode;

/**Best Time to Buy and Sell Stock III
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note: 
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * @author ShaoCheng
 * @version 1.0 2015-10-18
 */
/* ��Ѱһ����j����ԭ����price[0..n-1]�ָ�Ϊprice[0..j]��price[j..n-1]���ֱ������ε����profit��
 * �����Ż���
 * ���ڵ�j+1����price[0..j+1]�����profitʱ���ܶ๤�����ظ��ģ�����price[0..j]�����profit���Ѿ������ˡ�
 * ������Best Time to Buy and Sell Stock��������O(1)��ʱ���price[0..j]�Ƴ�price[0..j+1]�����profit��
 * ������δ�price[j..n-1]�Ƴ�price[j+1..n-1]��������˼�������ǿ�����O(1)��ʱ����price[j+1..n-1]�Ƴ�price[j..n-1]��
 * �����㷨��
 * ����l[i]��¼��price[0..i]�����profit��
 * ����r[i]��¼��price[i..n]�����profit��
 * ��֪l[i]����l[i+1]�Ǽ򵥵ģ�ͬ����֪r[i]����r[i-1]Ҳ�����ס�
 * �����������O(n)��ʱ���ҳ�����l[i]+r[i]����Ϊ��Ŀ����
 */
public class Solution {
	/*ʱ�临�Ӷ�O(n)*/
    public int maxProfit(int[] prices) {
    	if(prices.length == 0)
    		return 0;
    	
    	//���������������������
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
        
        //��������������������
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

/* ʱ�临�ӶȱȽϸ��ӣ��м���кܶ��ظ����� */
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