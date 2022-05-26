//URL: https://leetcode.com/problems/jump-game
//Difficulty: Medium
//Topic: DP

class Solution {
  public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) {
            return true;
        }
        
        vector<bool> dp(n, false);
        
        dp[n-1] = true;
        dp[n-2] = nums[n-2] > 0;
        
        for(int i=n-3; i >= 0; i--) {
            
            // first check if from the current step can reach the last one
            // if so, set the dp to true immediately
            if(i+nums[i] >= n-1) {
                dp[i] = true;
                continue;
            }
            
            // else, trace from its furthest jump until finding a true dp
            for(int j=i+nums[i];j>i;j--) {
                if(dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        
        return dp[0];
    }
};
