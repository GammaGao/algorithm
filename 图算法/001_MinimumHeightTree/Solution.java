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
 * (1) According to the definition of tree on Wikipedia: “a tree is an undirected
 * 		graph in which any two vertices are connected by exactly one path. In other
 * 		words, any connected graph without simple cycles is a tree.”
 * (2) The height of a rooted tree is the number of edges on the longest downward path
 *  	between the root and a leaf.
 *   
 * @author ShaoCheng
 * @version 1.0 2015-12-9  
 */

/* 图算法
 * BFS
 * BFS求图中距离最长的路径
 */
/*思路1：两次BFS
 * 很容易知道，树根肯定为图中路径最长的中间的点。只要知道图中最长的路径即可。第一次随机选取一点进行BFS，找出距离最远的点u
 * (此u必定为图中距离最长的路径的一端点)，再次以u为起始点BFS，找出最长的路径即可。
 */
public class Solution {
	private List<Integer>[] graph; //表示图，邻接表
	
	/**满足要求的高度最小的树的根
	 * @param n 图的Vetex的个数
	 * @param edges 图的边
	 * @return List
	 */
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        graph = new List[n];
        for(int i = 0; i <n; i++) {
        	graph[i] = new ArrayList<Integer>();
        }
        
        //edges转换邻接表
        for(int[] pair : edges) { //遍历二维数组每行
        	int first = pair[0];
        	int second = pair[1];
        	graph[first].add(second); //注意，每个vertex的值均在0-(n-1)之间
        	graph[second].add(first); //无向图
        }
        
        int[] dist = new int[n]; //存放每个顶点到源点的距离
        int[] pre = new int[n]; //BFS时，pre[v]=u表示存放点v的前置点u，追踪路径
        bfs(graph, n, 0, dist, pre);
        
        int u = 0;
        for(int i = 1; i < dist.length; i++) {
        	if(dist[u] < dist[i])
        		u = i;
        }
//        System.out.println(u);
        Arrays.fill(dist, 0); //清零
        Arrays.fill(pre, -1); //清-1
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
        	v = pre[v]; //获取前置节点
        }
        
        int size = path.size();
        if((size & 0x1) == 0) { //偶数长度
        	res.add(path.get(size>>1));
        	res.add(path.get((size>>1) - 1));
        }
        else{ //奇数长度
        	res.add(path.get(size>>1));
        }
        	
//        for(List l : graph) {
//        	for(int i = 0; i < l.size(); i++)
//        		System.out.print(l.get(i));
//        	System.out.println();
//        }
        
        return res;
    }
    
    /**图的BFS
     * @param graph 邻接表
     * @param vertex 图的顶点个数
     * @param start BFS起始点
     * @param dist 保存图中每个点距start的距离
     * @param pre 保存访问时，每个点的前置点，便于追踪路径（不能保存后置点）
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
    				pre[neighbor] = curr; //存放前置节点，这样便于查找路径
    			}
    		}
    	}
    }
}
