// URL : https://leetcode.com/problems/binary-tree-cameras
// Difficulty : Hard
// Topic : DP, Binary Tree
// Personal Notes :
// - The approach is to find the optimal solution of the children for ALL possible cases (DP dimension can be more than one).
//   like in this case, consider cases where the root is covered & not covered, root has camera and not, etc.
// - vector<int> is way easier to manage especially as function params and retval


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
    int minArray(vector<int> array) {
        int cur_min = array[0];
        for(int i=1;i<array.size();i++) {
            cur_min = min(cur_min, array[i]);
        }
        
        return cur_min;
    }
    
    vector<int> solve(TreeNode* root) {
        vector<int> retval = vector<int>(3);
        
        if(!root) {
            retval[0] = 0;
            retval[1] = 0;
            retval[2] = 9999999;
            
            return retval;
        }
        
        // Solve recursively to find the most optimal solution for the children
        // for all three states
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        
        
        // [State 0] Strict subtree : All children covered but not the root
        // calculated by the sum of state 1 from left and right
        retval[0] = left[1] + right[1];
        
        // [State 1] Normal subtree : All children covered including root but no camera here
        // calculated from the minimum between (left state 1 + right state 2 or left state 2 + right state 1)
        
        retval[1] = min(min(left[1],left[2])+right[2], left[2]+min(right[1],right[2]));
        
        // [State 2] Placed camera : All children covered and there's camera at root
        // calculated from minimum of left + minimum of right + 1 (the camera)
        retval[2] = 1 + minArray(left) + minArray(right);
        
        // cout << dp[0] << " " << dp[1] << " " << dp[2] << endl;
        
        return retval;
    }
    
    int minCameraCover(TreeNode* root) {
        vector<int> root_solution = solve(root);
        
        return min(root_solution[1], root_solution[2]);
    }
};
