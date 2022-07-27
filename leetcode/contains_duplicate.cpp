// URL : https://leetcode.com/problems/contains-duplicate
// Difficulty : Easy
// Topic : Array, Hash Table, Sorting
// Personal Notes : -
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
        
        for(int i=0;i< nums.size();i++) {
            if(m[nums[i]]) {
                return true;
            }
            
            m[nums[i]] = true;
        }
        
        return false;
    }
};
