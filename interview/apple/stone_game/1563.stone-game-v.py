#
# @lc app=leetcode id=1563 lang=python3
#
# [1563] Stone Game V
#

# @lc code=start
from functools import cache


class Solution:
    def stoneGameV(self, stoneValue: list[int]) -> int:
        
        n = len(stoneValue)
        if n==1:
            return 0
        
            
# @lc code=end

