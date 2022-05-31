// URL: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k
// Difficulty: Medium
// Topic: hash table

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> found = unordered_set<string>();
        
        if (k > s.length()) {
            return false;
        }
        
        for(int i=0; i<= s.length() - k; i++) {
            found.insert(s.substr(i,k));
        }
        
        return found.size () == pow(2,k);
    }
};
