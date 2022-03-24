/**
 * Given an m x n matrix
 * return all elements of the matrix in spiral order.
 */
 
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int top = 0, bottom = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        List<Integer> spiralList = new ArrayList<Integer>();
        while (left <= right && top <= bottom) { // while(true) also works
            for (int i=left; i <= right; i++) 
                spiralList.add(matrix[top][i]);
            if (++top > bottom) break;
            for (int i=top; i <= bottom; i++) 
                spiralList.add(matrix[i][right]);
            if (--right < left) break;
            for (int i=right; i >= left; i--) 
                spiralList.add(matrix[bottom][i]);
            if (--bottom < top) break;
            for (int i=bottom; i >= top; i--) 
                spiralList.add(matrix[i][left]);
            if (++left > right) break;
        }
        return spiralList;
    }
}
