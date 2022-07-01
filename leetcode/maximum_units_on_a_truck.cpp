// URL : https://leetcode.com/problems/maximum-units-on-a-truck/
// Difficulty : Easy
// Topic : Array, Greedy, Sorting
// Personal Notes :

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int curAmount = 0;
        int maxUnit = 0;
        
        for(int i=0;i<boxTypes.size();i++) {
            for(int j=0;j<boxTypes[i][0];j++) {
                maxUnit+= boxTypes[i][1];
                curAmount+=1;
                
                if(curAmount==truckSize) {
                    return maxUnit;
                }
            }
        }
        
        return maxUnit;
    }
};
