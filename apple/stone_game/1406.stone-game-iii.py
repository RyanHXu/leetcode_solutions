#
# @lc app=leetcode id=1406 lang=python3
#
# [1406] Stone Game III
#

# @lc code=start
from functools import cache


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        @cache
        def dp(l):
            if l > n-1:
                return 0
            
            return max(
              [sum(stoneValue[l:l+i+1]) - dp(l+i+1)
               for i in range(3)]  
            )
        
        res = dp(0)
        
        if res == 0:
            return "Tie"
        elif res >0:
            return "Alice"
        else:
            return "Bob"   
        
# @lc code=end

