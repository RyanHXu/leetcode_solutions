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
        if n==0:
            return 0
        k = len(costs[0])

        @cache
        def dp(house_num,color):
            if house_num == n-1:
                return costs[house_num][color]
            
            cost = math.inf
            
            for next_color in range(k):
                if next_color == color:
                    continue
                cost = min(cost, dp(house_num+1, next_color))
            return costs[house_num][color] + cost
        
        cost  = math.inf
        
        for color in range(k):
            cost = min(cost,dp(0,color))
            
        return cost
                    
# @lc code=end

