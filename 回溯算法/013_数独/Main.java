package leetcode;

public class Main {
	public static void main(String[] args){
		char[][] board = {"53..7....".toCharArray(),
						  "6..195...".toCharArray(),
						  ".98....6.".toCharArray(),
						  "8...6...3".toCharArray(),
						  "4..8.3..1".toCharArray(),
						  "7...2...6".toCharArray(),
						  ".6....28.".toCharArray(),
						  "...419..5".toCharArray(),
						  "....8..79".toCharArray()};
		Solution sl = new Solution();
		sl.solveSudoku(board);
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++)
				System.out.print(board[i][j] + " ");
			System.out.print("\n");
		}
	}
}