/**
 * Question:
 * Given the root of a binary tree, return all root-to-leaf paths in any order
 * A leaf is a node with no children.
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
    
    static void recursiveTreePath(TreeNode* root, string path, vector<string>& paths) {
        if (!root->right && !root->left) {
            paths.push_back(path+to_string(root->val));
            return;
        }
        if (root->left)
            recursiveTreePath(root->left, path+to_string(root->val)+"->", paths);
        if (root->right)
            recursiveTreePath(root->right, path+to_string(root->val)+"->", paths);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root)
            recursiveTreePath(root, "", paths);
        return paths;
        
    }
};
