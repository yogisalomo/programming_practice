# URL: https://leetcode.com/problems/longest-common-prefix/
# Level: easy
# Related topic: string

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        current_index = 0
        common_prefix = ""
        
        while(True):
            if(current_index == len(strs[0])):
                return common_prefix
            
            current_character = strs[0][current_index]
            
            for i in range(1, len(strs)):
                current_string = strs[i]
                if(current_index == len(current_string)):
                    return common_prefix
                
                if current_character != current_string[current_index]:
                    return common_prefix
            
            common_prefix += current_character
            current_index+=1
