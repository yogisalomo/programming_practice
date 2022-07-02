// URL : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Difficulty : Medium
// Topic : Array, Greedy, Sorting
// Personal Notes :
// - Do not think too literally when solving the question & end up over complicating the logic! Initially tried to keep max left & max right, max top & bottom, while actually
//   just need to find the biggest differences between two sorted members.
// - Biggest area of a square = product of maximum difference between x & y values

class Solution {
public:
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        int max_h = horizontalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++) {
            max_h = max(max_h,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_w = verticalCuts[0];
        for(int i=1; i<verticalCuts.size();i++) {
            max_w = max(max_w, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return (int) ((long long) max_h * max_w % 1000000007);
    }
};
