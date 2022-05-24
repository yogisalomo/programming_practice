// URL: https://leetcode.com/problems/house-robber
// Difficulty: Medium
// Topic: DP

class Solution {
  public:
    int rob(vector<int>& nums) {
        int max_amount[nums.size()];
        
        if(nums.size()==1) {
            return nums[0];
        }
        
        max_amount[0] = nums[0];
        max_amount[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        
        for(int i=2; i < nums.size(); i++) {
            if(max_amount[i-2] + nums[i] < max_amount[i-1]) {
                max_amount[i] = max_amount[i-1];
            }
            else {
                max_amount[i] = max_amount[i-2] + nums[i];
            }
        }
        
        return max_amount[nums.size()-1];
    }
};
