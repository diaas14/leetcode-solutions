/**
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 */
 
 class Solution {
    boolean visited[][];
    public boolean existPattern(char[][] board, String word, int row, int col, int idx) {
        if (idx == word.length())
            return true;
        if (visited[row][col] || board[row][col] != word.charAt(idx)) 
            return false;
        
        visited[row][col] = true;
        // check left
        if (col > 0 && existPattern(board, word, row, col-1, idx+1))
            return true;
        // check right
        if (col < board[0].length-1 && existPattern(board, word, row, col+1, idx+1))
            return true;    
        // check top
        if (row > 0 && existPattern(board, word, row-1, col, idx+1))
            return true; 
        // check bottom
        if (row < board.length-1 && existPattern(board, word, row+1, col, idx+1))
            return true; 
        visited[row][col] = false;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        visited = new boolean[board.length][board[0].length];
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (existPattern(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}
