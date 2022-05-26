// URL: https://leetcode.com/problems/delete-and-earn
// Difficulty:
// Topic: DP
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> added_points_cache(10001,0);
        int max_num = 0;
        int min_num = 10001;
        
        for(int i=0; i< nums.size(); i++) {
            added_points_cache[nums[i]] += nums[i];
            
            if(nums[i] > max_num) {
                max_num = nums[i];
            }
            if(nums[i] < min_num) {
                min_num = nums[i];
            }
        }
        
        vector<int> dp(max_num+1,0);
        
        dp[min_num] = added_points_cache[min_num];
        
        for(int i=min_num+1; i<max_num+1;i++) {
            if(added_points_cache[i] != 0) {
                if(added_points_cache[i-1] == 0) {
                    // Previous number didn't occur, so have no neighbor
                    dp[i] = added_points_cache[i] + dp[i-1];
                }
                else {
                    // check if deleting or not deleting is better
                    dp[i] = max(dp[i-1], dp[i-2] + added_points_cache[i]);
                }
            }
            else {
                //If the current number is 0, the maximum value is the same
                dp[i] = dp[i-1];
            }
        }
        
        return dp[max_num];
    }
};
