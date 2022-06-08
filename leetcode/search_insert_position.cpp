// URL : https://leetcode.com/problems/search-insert-position
// Difficulty : Easy
// Topic : Binary Search
// Personal Notes :
// - When resetting the boundary don't forget to +1 or -1 from the mid

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int center;
        
        while(left<=right) {
            center = left + (right-left)/2;
            
            if(nums[center] == target) {
                return center;
            }
            
            if(nums[center] > target) {
                right = center-1;
            }
            else {
                left = center+1;
            }
        }
        
        return left;
    }
};
