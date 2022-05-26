//URL: https://leetcode.com/problems/jump-game-ii
//Difficulty: Medium
//Topic: DP
class Solution {
  public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n<=2) {
            return n-1;
        }

        vector<int> dp(n, 10000);

        dp[n-1] = 0;
        dp[n-2] = 1;

        for(int i=n-3; i >= 0; i--) {
            int check_limit = min(n-1,i+nums[i]);

            int min_val = 100000;
            for(int j=check_limit;j>i;j--) {
                min_val = min(min_val, dp[j]);
            }
            dp[i] = 1+ min_val;
            // cout << i << ":" << dp[i] << endl;
         }

         return dp[0];
    }
};
