/* @TIELE: Single Number
 * 		Given an array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * @TIME:2015-6-30
 * @FROM:leetcode
 * @TYPE:位运算或哈希
 * @AUTHOR:PengSc
 */
import java.util.HashMap;
public class SingleNumber{
	/* 思路1：使用为运算，因为只有一个元素之出现一次，其他元素都出现两次
	 *		a^a=0, 0^b=b
	 * 性能：时间复杂度O(n)
	 */
	public static int singleNumber_1(int [] nums){
		int res = 0;
		for(int i:nums){ //i为元素变量，并不是索引值
		//for(int i = 0; i < nums.length; i++){
			res ^= i;
			// res ^= nums[i];
		}
		return res;
	}

	public static int singleNumber(int[] nums){
		int res = 0;
		HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
		for(int i = 0; i < nums.length; i++){
			if(!hmap.containsKey(nums[i])){ //如果map包含指定的key返回true,否则返回false
				hmap.put(nums[i], i);
			}
			else
				hmap.remove(nums[i]); //Removes the mapping for the specified key from this map if present
				//删除的是映射关系，key依然存在，map大小也不会减小, key->null
		}

		for(int i = 0; i < nums.length; i++){
			if(hmap.containsKey(nums[i]))
				res = nums[i];
		}
		return res;
	}

	public static void main(String[] args) {
		int[] nums = new int[]{1, 15, 1, 30, 10, 30, 15};
		int res = singleNumber(nums);
		System.out.print(res);
	}
}