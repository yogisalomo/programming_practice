// URL : https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/
// Difficulty : Medium
// Topic : Array, DP

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // Case 1 - The max subarray is in the middle of the array -> normal sub array
        int all_max = 0;
        int curr_max = 0;
        
        // Case 2 - The max subarray goes around the circular array -> SUM - min sub array
        // Solution: Compare the two case and return the bigger one
        int all_sum = 0;
        int curr_min = 0;
        int all_min = 999999;
        
        // Handling edge case of always negative array -> return its biggest element
        bool is_ever_positive = false;
        int biggest_number = -3 * 10000;
        
        for(int i=0; i< nums.size();i++) {
            curr_max += nums[i];
            curr_min += nums[i];
            all_sum += nums[i];
            
            if(nums[i] > 0 && !is_ever_positive) {
                is_ever_positive = true;
            }
            
            biggest_number = max(biggest_number, nums[i]);
            
            if(curr_min > 0) {
                curr_min = 0;
            }
            
            if(curr_max <0) {
                curr_max = 0;
            }
            
            all_max = max(all_max,curr_max);
            all_min = min(all_min,curr_min);
        }
        
        if(is_ever_positive){
            return max(all_sum-all_min,all_max);      
        }
        else {
            return biggest_number;
        }
    }
};
