// URL : https://leetcode.com/problems/length-of-last-word
// Difficulty : easy
// Topic : string
// Personal Note : - 
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int cur_len = 0;
        int last_len = 0;
        
        for(int i=0;i<s.length();i++) {
            char cur_char = s.at(i);
            
            if(cur_char == ' ') {
                if(cur_len>0) {
                    last_len = cur_len;   
                }
                cur_len=0;
            }
            else {
                cur_len++;
            }
        }
        
        return cur_len > 0 ? cur_len : last_len;
    }
};
