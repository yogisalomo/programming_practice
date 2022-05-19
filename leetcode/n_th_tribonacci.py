# URL: https://leetcode.com/problems/n-th-tribonacci-number/
# Level: easy
# Topic: DP
class Solution:
    def tribonacci(self, n: int) -> int:
        cache = {}
        def recur_tribonacci(i: int):
            if i <= 1:
                return i
            
            if i == 2:
                return 1
            
            if i in cache:
                return cache[i]
            
            cache[i] = recur_tribonacci(i-3) + recur_tribonacci(i-2) + recur_tribonacci(i-1)
            
            return cache[i]
        
        return recur_tribonacci(n)
        
