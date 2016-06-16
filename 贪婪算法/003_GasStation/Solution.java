package exam;

/**Gas Station
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
 * You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * 
 * @author ShaoCheng
 * @version 1.0 2015-12-15
 */

/* Whenever the sum is negative, reset it and let the car start from next point.
 * In the mean time, add up all of the left gas to total. If it's negative finally, return -1 since it's impossible to finish.
 * If it's non-negative, return the last point saved in res;
 */
public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
    	int res = 0;
    	int sum = 0;
    	int total = 0; //save the difference
    	for(int i = 0; i < gas.length; i++) {
    		sum += gas[i] - cost[i];
    		if(sum < 0) {
    			total += sum;
    			sum = 0; //reset
    			res = i+1; //save the next position
    		}
    	}
    	total += sum;
    	return total < 0 ? -1 : res; //total must be bigger than 0, otherwise -1.
    }
}