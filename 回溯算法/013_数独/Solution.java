package leetcode;

import java.util.Arrays;

/**
 *  9*9��������
 * @author ShaoCheng
 */
public class Solution {
    public void solveSudoku(char[][] board) {
    	dfs(board, 0);
    }
    
    /**��������������񣬱�����Ҳ��һ�ֱ����ƽⷽ����
     * @param board
     * @param idx 1-81������
     * @return �н⣬����true���޽⣬����false
     */
    public static boolean dfs(char[][] board, int idx){
    	if(idx == 81) //�ҵ���
    		return true;
    	int i = idx / 9; //������
    	int j = idx % 9;
    	if(board[i][j] != '.')
    		return dfs(board, idx + 1);
    	
    	//flag��¼1-9��9������ʹ�����
    	boolean[] flag = new boolean[10]; //1-9���飬���������1-9
    	validate(board, i, j, flag);
    	for(int k = 1; k <= 9; k++){
    		if(flag[k]){ //�����ֵk��flag�о��ҵ�������board[i][j]�޷���䡣
    			board[i][j] = (char)(k + '0');
    			if(dfs(board, idx + 1))
    				return true;
    		}
    	}
    	board[i][j] = '.'; //��ԭ���޽�
    	return false;
    }
    
    /**
     * @param board
     * @param row board�е�ǰ�����㣬�ĺ�����
     * @param col board�е�ǰ�����㣬��������
     * @param flag 1-9��9��������ǰ�С��м�����ռ�����
     */
    public static void validate(char[][] board, int row, int col, boolean[] flag){
    	Arrays.fill(flag, true); //����false
    	for(int k = 0; k < 9; k++){
    		if(board[row][k] != '.')
    			flag[board[row][k] - '0'] = false;
    		if(board[k][col] != '.')
    			flag[board[k][col] - '0'] = false;
    		int r = row/3 * 3 + k / 3; //��С����������
    		int c = col/3 * 3 + k % 3;
    		if(board[r][c] != '.')
    			flag[board[r][c] - '0'] = false;
    	}
    }
}