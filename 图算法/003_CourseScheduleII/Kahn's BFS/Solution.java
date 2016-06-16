package exam;

import java.util.*;

/**Course Schedule II
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * Some courses may have prerequisites, for example to take course 0 you have 
 * to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, return the 
 * ordering of courses you should take to finish all courses.
 * There may be multiple correct orders, you just need to return one of them. 
 * If it is impossible to finish all courses, return an empty array.
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 * 
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
 * Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
 * Another correct ordering is[0,2,1,3].
 * @author ShaoCheng
 * @version 1.0 2015-12-12
 */

/* Kahn's BFS topological algorithm, but output is reverse. */
public class Solution {
	List<Integer>[] grath;
	int[] res;
	
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        grath = new List[numCourses]; //at best, use List<List<Integer>> 
        for(int i = 0; i < numCourses; i++) {
        	grath[i] = new ArrayList<Integer>();
        }
        
        int[] indegree = new int[numCourses]; //ͳ��ÿ��������
        for(int[] edge : prerequisites) { //convert to adjacent list.
        	int first = edge[0];
        	int second = edge[1];
        	grath[first].add(second);
        	indegree[second]++;
        }
        
        bfs(grath, numCourses, indegree);
        int start = 0, end = res.length-1;
        while(start <= end) { //ע��BFS���������������ģ���ʵ����ֱ����bfs�������ţ��������ڴ˶��һ��
        	int temp = res[start];
        	res[start] = res[end];
        	res[end] = temp;
        	start++; end--;
        }
        return res;
    }
    
    /* Kahn-BFS */
    public void bfs(List<Integer>[] grath, int numCourses, int[] indegree) {
    	Queue<Integer> q = new ArrayDeque<Integer>();
    	res = new int[numCourses];
    	
    	for(int i = 0; i < numCourses; i++) { //���������Ϊ0�ĵ���������
    		if(indegree[i] == 0)
    			q.add(i);
    	}
    	int count = 0;
    	while(!q.isEmpty()) {
    		int curr = q.poll();
    		res[count++] = curr; //���ʵ�ǰ��
    		for(int neighbor : grath[curr]) { //��ȡ���ڵ㣬�������Ϊ0�ĵ��������ʶ���
    			if(--indegree[neighbor] == 0) {
    				q.add(neighbor);
    			}
    		}
    	}
    	if(count != numCourses) //exist cycle
    		res = new int[0];
    }
}