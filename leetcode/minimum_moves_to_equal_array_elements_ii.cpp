// URL : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
// Difficulty : Medium
// Topic : Array, Math
// Personal Note :
// - Learned about Central Tendency (mean, median, mode) and when to use them https://statistics.laerd.com/statistical-guides/measures-central-tendency-mean-mode-median.php
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int move = 0;
        
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size()/2];
        
        for(int i=0;i<nums.size();i++) {
            move+= abs(nums[i] - median);
        }
        
        return move;
    }
};
