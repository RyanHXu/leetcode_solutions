#
# @lc app=leetcode id=2029 lang=python3
#
# [2029] Stone Game IX
#

# @lc code=start
from functools import cache


class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        
        n = len(stones)
        @cache
        def dp(l,sum_of_removed):
            if l>n-1:
                return 0
            
# @lc code=end

