/**
 * Question:
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees 
 * of every node differ in height by no more than 1.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int balancedDepth(TreeNode* root) {
        if (!root) return 0;
        
        int left = balancedDepth(root->left);
        if (left == -1) return -1;
        
        int right = balancedDepth(root->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1)
            return -1;
        
        return max(left, right) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        return (balancedDepth(root) >= 0) ? true : false;
    }
};
