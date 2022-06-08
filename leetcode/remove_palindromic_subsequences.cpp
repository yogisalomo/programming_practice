// URL : https://leetcode.com/problems/remove-palindromic-subsequences
// Difficulty : easy
// Topic : Two pointer

class Solution {
public:
    int removePalindromeSub(string s) {
        int start_idx = 0;
        int end_idx = s.length() - 1;
      
        // Since the sequence only consist of two characters, the maximum steps
        // that might be needed are two, removing all 'a' and removing all 'b'
        // So we just need to check if the whole string is palindrome and return 1 if so
        // else just return 2.
        
        while(start_idx < end_idx) {
            if(s[start_idx] != s[end_idx]) {
                return 2;
            }
            
            start_idx++;
            end_idx--;
        }
        
        return 1;
    }
};
