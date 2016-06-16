package leetcode;

import java.util.Arrays;

/**
 *  9*9数独问题
 * @author ShaoCheng
 */
public class Solution {
    public void solveSudoku(char[][] board) {
    	dfs(board, 0);
    }
    
    /**深度优先搜索宫格，本质上也是一种暴力破解方法。
     * @param board
     * @param idx 1-81个宫格
     * @return 有解，返回true；无解，返回false
     */
    public static boolean dfs(char[][] board, int idx){
    	if(idx == 81) //找到解
    		return true;
    	int i = idx / 9; //求坐标
    	int j = idx % 9;
    	if(board[i][j] != '.')
    		return dfs(board, idx + 1);
    	
    	//flag记录1-9这9个数在使用情况
    	boolean[] flag = new boolean[10]; //1-9数组，索引方便从1-9
    	validate(board, i, j, flag);
    	for(int k = 1; k <= 9; k++){
    		if(flag[k]){ //如果数值k在flag中均找到，表明board[i][j]无法填充。
    			board[i][j] = (char)(k + '0');
    			if(dfs(board, idx + 1))
    				return true;
    		}
    	}
    	board[i][j] = '.'; //还原，无解
    	return false;
    }
    
    /**
     * @param board
     * @param row board中当前搜索点，的横坐标
     * @param col board中当前搜索点，的纵坐标
     * @param flag 1-9这9个数被当前行、列及宫格占用情况
     */
    public static void validate(char[][] board, int row, int col, boolean[] flag){
    	Arrays.fill(flag, true); //填充成false
    	for(int k = 0; k < 9; k++){
    		if(board[row][k] != '.')
    			flag[board[row][k] - '0'] = false;
    		if(board[k][col] != '.')
    			flag[board[k][col] - '0'] = false;
    		int r = row/3 * 3 + k / 3; //在小宫格中坐标
    		int c = col/3 * 3 + k % 3;
    		if(board[r][c] != '.')
    			flag[board[r][c] - '0'] = false;
    	}
    }
}