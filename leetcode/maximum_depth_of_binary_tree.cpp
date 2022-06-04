// URL : https://leetcode.com/problems/maximum-depth-of-binary-tree
// Difficulty : easy
// Topic: DFS

/**
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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        if(!root->left && !root->right){
            return 1;
        }
        int max_val = 1;
        max_val += max(maxDepth(root->left), maxDepth(root->right));
        
        return max_val;
    }
};
