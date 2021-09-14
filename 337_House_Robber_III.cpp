/**
 * The thief has found himself a new place for his thievery again. 
 * There is only one entrance to this area, called root.
 * Besides the root, each house has one and only one parent house. 
 * After a tour, the smart thief realized that all houses in this place form a binary tree. 
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Given the root of the binary tree, 
 * return the maximum amount of money the thief can rob without alerting the police.
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
    /*
    int robUtil(TreeNode* root, unordered_map<TreeNode*, int> memo) {
        if (!root) return 0;
        
        if (memo.find(root) != memo.end())
            return memo[root];
        
        if (!root->left && !root->right)
            return (memo[root] = root->val);
        
        int include = root->val;
        include += (root->left)? rob(root->left->left) +rob(root->left->right) : 0;
        include += (root->right)? rob(root->right->left) +rob(root->right->right) : 0;
        
        memo[root] = max(include, rob(root->left)+rob(root->right));
        return memo[root];
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return robUtil(root, memo);
    }
    */
    
    vector<int> robUtil(TreeNode* root) {
        if (!root) return vector<int>(2, 0);
        
        if (!root->left && !root->right)
            return vector<int>({root->val,0});
                    
        vector<int> leftChild = robUtil(root->left);
        vector<int> rightChild = robUtil(root->right);
        
        return vector<int>({root->val+leftChild[1]+rightChild[1], max(leftChild[0], leftChild[1])+max(rightChild[0], rightChild[1])});
        
    }
                                 
    int rob(TreeNode* root) {
        vector<int> res = robUtil(root);
        return (res[0] > res[1]) ? res[0] : res[1];
    }
                                 
};
