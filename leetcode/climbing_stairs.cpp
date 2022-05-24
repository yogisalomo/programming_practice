// URL: https://leetcode.com/problems/climbing-stairs/
// Difficulty: Easy
// Topic: DP

class Solution {
public:
    int climbStairs(int n) {
        int steps[n+1]; // plus 1 because we need to include the index of the last stair (the base case)
        
        steps[n-1] = 1;
        steps[n] = 1;
        
        for(int i=n-2; i >= 0; i--) { 
            steps[i] = steps[i+1] + steps[i+2];
        }
        
        return steps[0];
    }
};
