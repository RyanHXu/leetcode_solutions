#
# @lc app=leetcode id=265 lang=python3
#
# [265] Paint House II
#

# @lc code=start
from functools import cache
import math

class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n = len(costs)
        n2 = len(costs[0])
        if n==0:
            return 0
        
        @cache
        def dp(i,color):
            res = costs[i][color]
            
            for col in range(n2):
                if col == n-1:
                    pass
                if col == color
                    
# @lc code=end

