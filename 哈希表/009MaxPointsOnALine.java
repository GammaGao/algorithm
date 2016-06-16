/**@TITLE: Max Points on a Line(��һ��ֱ���ϵ�������)
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

/**˼·������ж��������Ƿ���һ��ֱ���ϣ�(x1, y1)��(x2, y2)��(x3, y3)�� ��Ȼ��
 * 		б��k1 = (y2-y1)/(x2-x1)��б��k2=(y3-y1)/(x3-x1)��ȣ����й�����(x1,y1)��Ȼ
 * 		��һ��ֱ���ϡ���Ȼ�������������ֱ�ߴ�ֱ��X��ĵ㡣
 * ���ܣ�ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
 */
public class Solution {
    public int maxPoints(Point[] points) {
    	if(points.length < 3)
    		return points.length;
    	
    	int max = 0;
    	//��ϣ���д�ŵ���б��->��һ��ֱ���ϵĵ�ĸ���
    	HashMap<Double, Integer> hmap = new HashMap<Double, Integer>();
    	for(int i = 0; i < points.length; i++){
    		hmap.clear();
    		int numVertical = 1, local = 0, duplicate = 0;
    		for(int j = i + 1; j < points.length; j++){
    			if(points[i].x == points[j].x){
    				if(points[i].y == points[j].y)
    					duplicate++; //Ϊ�δ����ظ��ĵ㣬���Գ��������ظ��ĵ�
    				else //б�������
    					numVertical++;
    			}
    			else{ //����б��
    				int tmp = 0;
    				double k = 0;
    				if(points[j].y != points[i].y) //java�г���-0.0��0.0�����
    					k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
    				else
    					k = 0;  //�������java�г���-0.0��0.0�����
    				if(!hmap.containsKey(k))
    					hmap.put(k, 2);
    				else{
						tmp = hmap.get(k);
						hmap.put(k, ++tmp); //put()Ҳ���Ը���valֵ
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