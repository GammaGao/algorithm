package exam;

import java.util.*;

/**TITLE:Minimum Height Trees
 * For a undirected graph with tree characteristics, we can choose any node as the root. 
 * The result graph is then a rooted tree. Among all possible rooted trees, those with minimum
 * height are called minimum height trees (MHTs). Given such a graph, write a function to find
 * all the MHTs and return a list of their root labels.
 * 
 * Format:
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n 
 * and a list of undirected edges (each edge is a pair of labels).You can assume that no duplicate
 * edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus
 * will not appear together in edges.
 * 
 * Example 1:
 * Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3
 * return [1]
 * 
 * Example 2:

 * Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
     0  1  2
      \ | /
        3
        |
        4
        |
        5
 * return [3, 4]
 *
 * Note:
 * (1) According to the definition of tree on Wikipedia: ��a tree is an undirected
 * 		graph in which any two vertices are connected by exactly one path. In other
 * 		words, any connected graph without simple cycles is a tree.��
 * (2) The height of a rooted tree is the number of edges on the longest downward path
 *  	between the root and a leaf.
 *   
 * @author ShaoCheng
 * @version 1.0 2015-12-9  
 */

/* ͼ�㷨
 * BFS
 * BFS��ͼ�о������·��
 */
/*˼·1������BFS
 * ������֪���������϶�Ϊͼ��·������м�ĵ㡣ֻҪ֪��ͼ�����·�����ɡ���һ�����ѡȡһ�����BFS���ҳ�������Զ�ĵ�u
 * (��u�ض�Ϊͼ�о������·����һ�˵�)���ٴ���uΪ��ʼ��BFS���ҳ����·�����ɡ�
 */
public class Solution {
	private List<Integer>[] graph; //��ʾͼ���ڽӱ�
	
	/**����Ҫ��ĸ߶���С�����ĸ�
	 * @param n ͼ��Vetex�ĸ���
	 * @param edges ͼ�ı�
	 * @return List
	 */
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        graph = new List[n];
        for(int i = 0; i <n; i++) {
        	graph[i] = new ArrayList<Integer>();
        }
        
        //edgesת���ڽӱ�
        for(int[] pair : edges) { //������ά����ÿ��
        	int first = pair[0];
        	int second = pair[1];
        	graph[first].add(second); //ע�⣬ÿ��vertex��ֵ����0-(n-1)֮��
        	graph[second].add(first); //����ͼ
        }
        
        int[] dist = new int[n]; //���ÿ�����㵽Դ��ľ���
        int[] pre = new int[n]; //BFSʱ��pre[v]=u��ʾ��ŵ�v��ǰ�õ�u��׷��·��
        bfs(graph, n, 0, dist, pre);
        
        int u = 0;
        for(int i = 1; i < dist.length; i++) {
        	if(dist[u] < dist[i])
        		u = i;
        }
//        System.out.println(u);
        Arrays.fill(dist, 0); //����
        Arrays.fill(pre, -1); //��-1
        bfs(graph, n, u, dist, pre);
        int v = 0;
        for(int i = 1; i < dist.length; i++) {
        	if(dist[v] < dist[i])
        		v = i;
        }
//        System.out.println(v);
        
        List<Integer> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        while(v != -1) {
        	path.add(v);
        	v = pre[v]; //��ȡǰ�ýڵ�
        }
        
        int size = path.size();
        if((size & 0x1) == 0) { //ż������
        	res.add(path.get(size>>1));
        	res.add(path.get((size>>1) - 1));
        }
        else{ //��������
        	res.add(path.get(size>>1));
        }
        	
//        for(List l : graph) {
//        	for(int i = 0; i < l.size(); i++)
//        		System.out.print(l.get(i));
//        	System.out.println();
//        }
        
        return res;
    }
    
    /**ͼ��BFS
     * @param graph �ڽӱ�
     * @param vertex ͼ�Ķ������
     * @param start BFS��ʼ��
     * @param dist ����ͼ��ÿ�����start�ľ���
     * @param pre �������ʱ��ÿ�����ǰ�õ㣬����׷��·�������ܱ�����õ㣩
     */
    public void bfs(List<Integer>[] graph, int vertex, int start, int[] dist, int[] pre) {
    	boolean[] visited = new boolean[vertex];
    	Queue<Integer> q = new ArrayDeque<Integer>();
    	q.add(start);
    	visited[start] = true;
    	dist[start] = 0;
    	
    	while(!q.isEmpty()) {
    		int curr = q.poll();
    		for(int i = 0; i < graph[curr].size(); i++) {
    			int neighbor = graph[curr].get(i);
    			if(!visited[neighbor]) {
    				dist[neighbor] = dist[curr] + 1;
    				visited[neighbor] = true;
    				q.add(neighbor);
    				pre[neighbor] = curr; //���ǰ�ýڵ㣬�������ڲ���·��
    			}
    		}
    	}
    }
}
