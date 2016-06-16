package exam;

/**二维数组螺旋打印
 * 示例：
 * 给定二维数组
 * 1,2,3
 * 4,5,6
 * 7,8,9
 * 其打印顺序为1,2,3,6,9,8,7,4,5
 * @author ShaoCheng
 * @version 1.0 2015-12-11
 * 网信理财面试(第3面)
 */
public class Solution {
	/* 循环实现 */
	public static void rotatingPrint(int[][] a) {
		if(a == null)
			return;
		int m = a.length;
		int n = a[0].length;
		
		int row = 0, row_l = m-1;
		int col = 0, col_l = n-1;
		while(row <= row_l && col <= col_l) {
			int i = row, j = col;
			if(i == row) {
				while(j <= col_l)
					System.out.print(a[i][j++]+" ");
				j--;
			}
			if(j == col_l) {
				i++;
				while(i <= row_l)
					System.out.print(a[i++][j] +" ");
				i--;
			}
			if(i == row_l) {
				j--;
				while(j >= col)
					System.out.print(a[i][j--] + " ");
				j++;
			}
			if(j == col) {
				i--;
				while(i > row)
					System.out.print(a[i--][j] + " ");
				i++;
			}
			row++;
			col++;
			row_l--;
			col_l--;
		}
	}

	/* 递归实现 */
	public static void rotatingPrint(int[][] a, int m, int n, int row, int col) {
		if(row < m && col < n) {
			int i = row, j = col;
			while(j <= n-1)
				System.out.print(a[i][j++] + " ");
			j--;
			while(++i <= m-1)
				System.out.print(a[i][j] + " ");
			i--;
			while(--j >= col)
				System.out.print(a[i][j] + " ");
			j++;
			while(--i > row)
				System.out.print(a[i][j] + " ");
			rotatingPrint(a, m-1, n-1, row+1, col+1);
		}
	}
}
