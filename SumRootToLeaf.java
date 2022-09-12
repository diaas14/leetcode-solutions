/**
 * 129_Sum_Root_to_Leaf_Numbers
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * Each root-to-lea129_Sum_Root_to_Leaf_Numbersf path in the tree represents a number.
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers. 
 * Test cases are generated so that the answer will fit in a 32-bit integer.
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class SumRootToLeaf {
    private int sum = 0;
    
    public void sumNumbers(TreeNode root, int tempSum) {
        int currSum = tempSum * 10 + root.val;
        if (root.left == null && root.right == null)
            sum += currSum;
        if (root.left != null)
            sumNumbers(root.left, currSum);
        if (root.right != null)
            sumNumbers(root.right, currSum);
    }
    
    public int sumNumbers(TreeNode root) {
        sumNumbers(root, 0);
        return sum;
    }
}
