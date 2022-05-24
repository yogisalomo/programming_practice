// URL: https://leetcode.com/problems/min-cost-climbing-stairs
// Difficulty: Easy
// Topic: DP

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost[cost.size()];
        
        min_cost[cost.size()-1] = cost[cost.size()-1];
        min_cost[cost.size()-2] = cost[cost.size()-2];
        
        for(int i=cost.size()-3; i >= 0; i--) {
            if(min_cost[i+1] < min_cost[i+2]){
                min_cost[i] = min_cost[i+1];
            }
            else {
                min_cost[i] = min_cost[i+2];
            }
            
            min_cost[i] += cost[i];
        }
        
        // return min_cost[cost.size()-1];
        if (min_cost[1] < min_cost[0]) {
            return min_cost[1];
        }
        else {
            return min_cost[0];
        }
    }
};
