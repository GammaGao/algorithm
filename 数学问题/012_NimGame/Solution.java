package leetcode;

/**Nim Game(取石子游戏)
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. 
 * The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 * For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 * @author ShaoCheng
 * @version 1.0 2015-10-17
 */

/* n=1，甲赢；n=2，甲赢；n=3，甲赢；n=4乙赢；n=5，只有甲先取1颗，剩余4颗让乙先手，乙肯定输，甲赢；
 * n=6甲先取2颗，剩余4颗让乙先手，乙必输，甲赢；其他类似
 *  */
public class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}