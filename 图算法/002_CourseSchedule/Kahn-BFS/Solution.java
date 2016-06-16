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
 */
/* Kahn�㷨--BFS�������� */
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
        int[] indegree = new int[numCourses];
        for(int[] edge : prerequisites) { //����ÿ����������
        	int first = edge[0];
        	int second = edge[1];
        	grath[first].add(second);
        	indegree[second]++;
        }
        
        bfs(numCourses, indegree);
        return res;
    }
    
    /* Kahn�㷨(BFS) - ʹ�����������ж��Ƿ���ڻ�  */
    public void bfs(int numCourses, int[] indegree) {
    	Queue<Integer> q = new ArrayDeque<Integer>();
    	int counter = 0; //���ʵĽڵ��������
    	
    	for(int i = 0; i < numCourses; i++) { //���������Ϊ0�ĵ�������
    		if(indegree[i] == 0)
    			q.add(i);
    	}
    	
    	while(!q.isEmpty()) {
    		int curr = q.poll();
    		counter++;
    		for(int i = 0; i < grath[curr].size(); i++) {
    			int neighbor = grath[curr].get(i);
    			if(--indegree[neighbor] == 0) {
    				q.add(neighbor);
    			}
    		}
    	}
		if(counter != numCourses) {
			res = false;
			return;
		}
    	res = true;
    }
}
