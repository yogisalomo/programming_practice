//URL: https://leetcode.com/problems/house-robber-ii/
//Difficulty: Medium
//Topic: DP
class Solution {
  public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) {
            return nums[0];
        }
        
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i < n-1;i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        int even_max = dp[n-2];
        
        dp.clear();
        dp = vector<int>(n, 0);
        
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for(int i=3;i < n;i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        int odd_max = dp[n-1];
        
        return max(odd_max, even_max);
    }
};
