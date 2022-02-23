#
# @lc app=leetcode id=877 lang=python3
#
# [877] Stone Game
#

# @lc code=start
from functools import cache


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        
        
        
# @lc code=end




class Solution2:
    def stoneGame(self, piles: List[int]) -> bool:
        
        @cache
        def dp(i,j):
            if i>j:
                return 0
            if i==j:
                return piles[i]
            return max(
                piles[i] - dp(i+1, j),
                piles[j] - dp(i, j-1)
                )
            
        return dp(0,len(piles)-1)>0