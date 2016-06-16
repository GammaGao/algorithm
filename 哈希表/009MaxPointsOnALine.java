/**@TITLE: Max Points on a Line(在一条直线上的最多点数)
 * 		Given n points on a 2D plane, find the maximum number of points that lie on
 *  	the same straight line.
 *  @TIME:2015-7-9
 *  @FROM:leetcode
 *  @AUTHOR:PengSc
 */
package leetcode;

import java.util.HashMap;

//Definition for a point.
class Point {
    int x;
    int y;
    Point() { x = 0; y = 0; }
    Point(int a, int b) { x = a; y = b; }
}

/**思路：如何判断三个点是否在一条直线上，(x1, y1)、(x2, y2)、(x3, y3)， 必然有
 * 		斜率k1 = (y2-y1)/(x2-x1)与斜率k2=(y3-y1)/(x3-x1)相等，且有公共点(x1,y1)必然
 * 		在一条直线上。当然考虑特殊情况，直线垂直于X轴的点。
 * 性能：时间复杂度O(n^2)，空间复杂度O(n)
 */
public class Solution {
    public int maxPoints(Point[] points) {
    	if(points.length < 3)
    		return points.length;
    	
    	int max = 0;
    	//哈希表中存放的是斜率->在一条直线上的点的个数
    	HashMap<Double, Integer> hmap = new HashMap<Double, Integer>();
    	for(int i = 0; i < points.length; i++){
    		hmap.clear();
    		int numVertical = 1, local = 0, duplicate = 0;
    		for(int j = i + 1; j < points.length; j++){
    			if(points[i].x == points[j].x){
    				if(points[i].y == points[j].y)
    					duplicate++; //为何处理重复的点，测试程序会给出重复的点
    				else //斜率无穷大
    					numVertical++;
    			}
    			else{ //正常斜率
    				int tmp = 0;
    				double k = 0;
    				if(points[j].y != points[i].y) //java中出现-0.0与0.0不相等
    					k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
    				else
    					k = 0;  //避免出现java中出现-0.0与0.0不相等
    				if(!hmap.containsKey(k))
    					hmap.put(k, 2);
    				else{
						tmp = hmap.get(k);
						hmap.put(k, ++tmp); //put()也可以更新val值
    				}
    				tmp = hmap.get(k);
					local = Math.max(local, tmp);
    			}
    		}
    		local = Math.max(local + duplicate, numVertical + duplicate);
    		max = Math.max(max, local);
    	}
        return max;
    }
}