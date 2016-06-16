package leetcode;

/**Add Digits
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * Follow up:
 * @TODO Could you do it without any loop/recursion in O(1) runtime?
 * @author ShaoCheng
 */
public class Solution {
    public int addDigits(int num) {
    	int n = num;
    	int sum = 0;
        while(n != 0){
        	sum += n%10;
        	n /= 10;
        	if(n == 0){
        		n = sum;
        		sum = 0;
        		if(n/10 == 0)
        			break;
        	}
        }
        return n;
    }
}