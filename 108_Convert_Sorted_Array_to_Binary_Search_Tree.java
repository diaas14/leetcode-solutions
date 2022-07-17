/**
 * Given an integer array nums where the elements are sorted in ascending order, 
 * convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree 
 * in which the depth of the two subtrees of every node never differs by more than one.
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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0)
            return null;
        return sortedArrayToBSTUtil(nums, 0, nums.length - 1);
    }
    
    public TreeNode sortedArrayToBSTUtil(int[] nums, int low, int high) {
        if (low > high)
            return null;
        int mid = (high - low)/2 + low;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = sortedArrayToBSTUtil(nums, low, mid - 1);
        root.right = sortedArrayToBSTUtil(nums, mid + 1, high); 
        return root;
    }
}
