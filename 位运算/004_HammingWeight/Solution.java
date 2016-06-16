package leetcode;

/**Number of 1 Bits(Hamming weight)
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 * @author ShaoCheng
 * @version 1.0 2015-10-16
 */
public class Solution {
    // you need to treat n as an unsigned value
	/* 最优算法 */
    public int hammingWeight(int n) {
    	int res = 0;
        while(n != 0){
        	res++;
        	n &= n-1;
        }
        return res;
    }
    
    //局限性
    public static int hammingWeightII(int n){
    	int res = 0;
    	for(int i = 0; i < 32; i++){
    		int k = 1 << i;
    		if((n & 1 << i) != 0)
    			res++;
    	}
    	return res;
    }
}