//URL: https://leetcode.com/problems/maximum-subarray
//Difficulty: Easy
//Topic: DP, DnC

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = -999999;
        
        for(int i=0;i<nums.size();i++) {
            cur_sum += nums[i];
            if(cur_sum > max_sum) {
                max_sum = cur_sum;
            }
            
            if(cur_sum < 0) {
                cur_sum = 0;
            }
        }
        
        return max_sum;
    }
};
