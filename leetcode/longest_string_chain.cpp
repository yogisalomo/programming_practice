// URL : https://leetcode.com/problems/longest-string-chain/submissions/
// Difficulty : Medium
// Topics : DP, Hash Table, String
// Personal Notes :
// - Usage of std::sort for string based on their length
// - std::string.erase() - Although it returns a string, it deletes the character in the original string as well!

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort the vector based on length 
        std::sort(words.begin(), words.end(), []
            (const std::string& first, const std::string& second){
                return first.size() < second.size();
            });
        
        std::map<std::string, int> max_length = std::map<std::string, int>();
        int retval = 1;
        
        for(int i=0; i < words.size(); i++) {
            string curr_word = words[i];
            
            // Edge case of one character string
            if(curr_word.size()==1) {
                max_length[curr_word] = 1;
                retval = 1;
            }
            else {
                int curr_word_max_length = 1;
                
                for(int j=0; j < curr_word.size();j++) {
                    string erased_word = curr_word;
                    
                    erased_word.erase(j,1);

                    if(max_length.find(erased_word) != max_length.end() && max_length[erased_word] + 1 > curr_word_max_length) {
                        curr_word_max_length = max_length[erased_word] + 1;
                    }
                }
                
                max_length[curr_word] = curr_word_max_length;
                
                if(curr_word_max_length > retval) {
                    retval = curr_word_max_length;
                }
            }
        }
        
        return retval;
    }
};
