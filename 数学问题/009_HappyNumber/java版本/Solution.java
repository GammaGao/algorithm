package leetcode;

import java.util.HashMap;
public class Solution {
    public boolean isHappy(int n) {
    	HashMap<Integer, Boolean> hm = new HashMap<>();
    	while(n != 1) {
    		n = SumOfSquares(n);
    		if(hm.containsKey(n))
    			return false;
    		hm.put(n, true);
    	}
    	return true;
    }
    
    private int SumOfSquares(int n) {
    	int sum = 0;
    	int digit;
    	while(n != 0) {
    		digit = n % 10;
    		n /= 10;
    		sum += digit * digit;
    	}
    	return sum;
    }
}