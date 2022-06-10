// URL : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// Difficulty : Medium
// Topic : Two Pointer
// Personal Notes:
// - Don't overcomplicate, if the n test case is still feasible, use simpler logic
//   (i.e. tried to use BST while simply incrementing/decrementing start and end would work)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int end = numbers.size() - 1;
        int start = 0;
        vector<int> retval = vector<int>();
        while(numbers[start] + numbers[end] != target) {
            
            if(numbers[start] + numbers[end] > target) {
                end-=1;
            }
            else {
                start+=1;
            }
        }
        
        retval.push_back(start+1);
        retval.push_back(end+1);
        
        return retval;
    }
};
