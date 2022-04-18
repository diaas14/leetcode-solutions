/**
 * Given the root of a binary search tree (BST) with duplicates, 
 * return all the mode(s) (i.e., the most frequently occurred element) in it.
 * If the tree has more than one mode, return them in any order.
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
    
    Integer maxFreq = Integer.MIN_VALUE, currFreq = 0, prevVal = Integer.MIN_VALUE;
    int [] resArr;
    List<Integer> resList = new ArrayList<Integer>();
    public int[] findMode(TreeNode root) {
        traverse(root);
        
        resArr = new int[resList.size()];
        for (int i=0; i<resList.size(); i++) 
            resArr[i] = resList.get(i);
        return resArr;
    }
    
    void traverse(TreeNode root) {
        if (root == null) return;
        traverse(root.left);
        if (root.val == prevVal)
            currFreq ++;
        else {
            prevVal = root.val;
            currFreq = 1;
        }
        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            resList.clear();
            resList.add(prevVal);
        } else if (currFreq == maxFreq) {
            resList.add(prevVal);
        }
        traverse(root.right);
    }
    
}
