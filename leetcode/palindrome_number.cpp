// URL : https://leetcode.com/problems/palindrome-number
// DIfficulty : easy
// Topic : Math
// Personal Note :
// - Getting a number's character in a specific index: (int) floor(x / pow(10,i)) % 10

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        
        if(x==0) {
            return true;
        }
        
        int n_digits = floor(log10(x));
        
        int i = 0;
        
        while(i < n_digits) {
            int r_digit = (int) floor(x / pow(10,i)) % 10;
            int l_digit = (int) floor( x / pow(10,n_digits)) % 10;
            
            if(r_digit != l_digit) {
                return false;
            }
            
            i+=1;
            n_digits-=1;
        }
        
        return true;
    }
};
