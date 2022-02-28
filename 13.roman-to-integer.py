#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#

# NOTE: corner case IX & XI 
# scan from left to right
# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {
            "I":    1,
            "V":    5,
            "X":   10,
            "L":   50,
            "C":  100,
            "D":  500,
            "M": 1000
        }
        
        res = dic[s[0]]
        
        for i in range(1,len(s)):
            prev = dic[s[i-1]]
            curr = dic[s[i]]
            
            if prev < curr:
                res += curr - prev*2
            else:
                res += curr
                
        return res
        

# @lc code=end
