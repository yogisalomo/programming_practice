// URL : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Difficulty : Medium
// Topic : String, Greedy
// Personal Note :

class Solution {
public:
    int minPartitions(string n) {
        
        int cur_max = 0;
        
        for(int i=0;i<n.length();i++) {
            char x = n.at(i);
            
            cur_max = max(cur_max, x - '0');
        }
        
        return cur_max;
    }
};
