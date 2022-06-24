// URL : 
// Difficulty : easy
// Topics : Two pointers
// Personal Note :
// - Don't try over-optimizing everything and ends up making the logic too complicated
//   (I tried to avoid nums[k] = nums[i] when i == k but ended up confused)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int k = 0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
