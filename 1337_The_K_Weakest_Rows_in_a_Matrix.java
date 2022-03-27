/** You are given an m x n binary matrix 
 * mat of 1's (representing soldiers) and 0's (representing civilians). 
 * The soldiers are positioned in front of the civilians. 
 * That is, all the 1's will appear to the left of all the 0's in each row.
 * A row i is weaker than a row j if one of the following is true:
 * The number of soldiers in row i is less than the number of soldiers in row j.
 * Both rows have the same number of soldiers and i < j.
 * Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
 */
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int [] strengths = new int [mat.length];

        for (int i=0; i<mat.length; i++) {
            int j=0;
            for(; j<mat[i].length; j++) {
                if (mat[i][j] != 1) break;
            }
            strengths[i] = j * mat.length + i;
        } 
        Arrays.sort(strengths);
        for (int i=0; i<k; i++) {
            strengths[i] %= mat.length;
        }
        return Arrays.copyOfRange(strengths, 0, k);
    }
}
