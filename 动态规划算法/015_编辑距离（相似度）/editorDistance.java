package leetcode;

/**编辑距离
 * 非常经典的动态规划问题
 * 编辑距离在求相似度方面有着十分重要的应用：DNA相似、论文抄袭、自然语言处理等。
 * @author ShaoCheng
 * @version 1.0 2015-10-25
 */
// 非递归实现，时间复杂度O(m*n)
class Main{
	public static void main(String[] args){
		System.out.println(editDistance("sting", "cbsting"));
		System.out.println();
		System.out.println(editDistance("sailn", "failing"));
	}
	
	public static int editDistance(String s1, String s2){
		int[][] a = new int[s1.length()+1][s2.length()+1];
		for(int i = 0; i <= s1.length(); i++)
			a[i][0] = i;
		for(int j = 0; j <= s2.length(); j++)
			a[0][j] = j;
		
		for(int j = 1; j < s2.length()+1; j++){
			for(int i = 1; i < s1.length()+1; i++){
				int d = 1;
				if(s2.charAt(j-1) == s1.charAt(i-1)){
					d = 0;
				}
				int t = Math.min(a[i-1][j] + 1, //删除
						a[i][j-1] + 1); //增加
				a[i][j] = Math.min(a[i-1][j-1] + d, //替换
						t);
			}
		}
		
		for(int i = 0; i <= s1.length(); i++){
			for(int j = 0; j <= s2.length(); j++)
				System.out.print(a[i][j] + " ");
			System.out.print('\n');
		}
		return a[s1.length()][s2.length()];
	}
}