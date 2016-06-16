package exam;

import java.util.*;

/**Course Schedule
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses? For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 
 * you should also have finished course 1. So it is impossible.
 * 
 * Hints:
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * 
 * @author ShaoCheng
 * @version 1.0 2015-12-11
 */

/* DFS�㷨
 * ���Ƿ���ͨͼʱ��ʱ�临�Ӷ�O(v*v)
 * ����ʱ��O(v)
 */
public class Solution {
	private List<Integer>[] grath; //ͼ
	private boolean res;
	
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(numCourses <= 0)
        	return false;
        grath = new List[numCourses]; //��û���List<List<Integer>>
        for(int i = 0; i < numCourses; i++) {
        	grath[i] = new ArrayList<>();
        }
        
        for(int[] edge : prerequisites) {
        	int first = edge[0];
        	int second = edge[1];
        	grath[first].add(second);
        }
        
        int[] currPath = new int[numCourses];
        res = true; //no exist cycle
        for(int i =0; i < numCourses; i++) { //���Ƿ���ͨͼ���Ӵ�ѭ��
        	if(!res)
        		break;
        	if(currPath[i] == 0) //�Ӵ˾�ӿ��ٶ�
        		dfs(grath, i, currPath);
        }
        return res;
    }
    
    /* ʹ��DFS����ʱ����Ԫ���ڲ���ջ�ڣ������ջ�ڵĻ���˵������Ȧ��  */
    public void dfs(List<Integer>[] grath, int curr, int[] currPath) {
        // 0 for white, unvisited δ����
        // 1 for grey, in stack ����ջ��
        // 2 for black, fully explored ���ʹ���������ջ��
    	currPath[curr] = 1;
    	for(int i = 0; i < grath[curr].size(); i++) {
    		if(!res)
    			return;
    		int neighbor = grath[curr].get(i);
    		if(currPath[neighbor] == 0) {
    			dfs(grath, neighbor, currPath);
    			//currPath[neighbor] = 2; //�ѳ�ջ���ѷ��ʹ�
    		}
    		else if(currPath[neighbor] == 1) {
    			res = false; //exist cycle
    			return;
    		}
    	}
    	currPath[curr] = 2;
    }
}