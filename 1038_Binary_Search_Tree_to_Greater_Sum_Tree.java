/**
 * Given the root of a Binary Search Tree (BST), 
 * convert it to a Greater Tree such that every key of the 
 * original BST is changed to the original key
 * plus the sum of all keys greater than the original key in BST.
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
class Solution {
    
    private int prevSum = 0;
    
    public TreeNode bstToGst(TreeNode root) {
        if (root == null) return root;
        
        root.right = bstToGst(root.right);
        root.val = (prevSum += root.val);
        root.left = bstToGst(root.left);
        
        return root;
    }
}
