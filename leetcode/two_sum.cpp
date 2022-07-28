// URL : https://leetcode.com/problems/two-sum
// Difficulty : Easy
// Topic : Array, Hash Table
// Personal Notes:
// - When working with map/array of integer, don't use if(x) to check existence because it might return false negative on 0 value!!!

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        
        vector<int> retval;
        
        for(int i=0;i<nums.size();i++) {
            if(m.find(nums[i]) != m.end()) {
                retval.push_back(i);
                retval.push_back(m[nums[i]]);
                return retval;
            }
            m[target - nums[i]] = i;
        }
        
        return retval;
    }
};
