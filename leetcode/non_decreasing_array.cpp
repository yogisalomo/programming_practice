// URL : https://leetcode.com/problems/non-decreasing-array/
// Difficulty : Medium
// Topic : Array
// Personal Note :
// - Pay close attention to Edge Cases (e.g. using > when should've been >= and missing a case)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool isChanged = false;
        
        for(int i=0;i< nums.size()-1;i++) {
            if(nums[i] > nums[i+1]) {
                // If a change has happened before, then it's false
                if(isChanged) {
                    return false;
                }
                
                if(i==0 || nums[i+1] >= nums[i-1]) {
                    nums[i]  = nums[i+1];
                }
                else {
                    nums[i+1] = nums[i];
                }
                
                isChanged = true;
            }
        }
        
        return true;
    }
};
