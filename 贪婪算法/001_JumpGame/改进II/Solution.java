package exam;

/**Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 * @author ShaoCheng
 * @version 1.0 2015-12-6
 * @see Greedy�㷨
 */

/* ���������һ��Ŀ���ɵ����ζ�ţ�ǰ�����е��б�������Ϊi�ĵ㣬��i+val >= Ŀ��������,����ܰ����е�i+valֵ������¼�¡�
 * ̰����˼·
 */
public class Solution {
    public boolean canJump(int[] nums) {
    	int reachable = 0;
        for(int i = 0; i < nums.length; i++) { //����ÿ���㣬�ж���ɴ���
        	if(reachable < i) //�����i���ɴ����ĵ�ض����ɴ�
        		return false;
        	reachable = reachable > i + nums[i] ? reachable : i + nums[i];
        }
        return true;
    }
}
