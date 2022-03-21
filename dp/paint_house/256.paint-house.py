#
# @lc app=leetcode id=256 lang=python3
#
# [256] Paint House
#

# @lc code=start
from distutils.command.config import config
from functools import cache


class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        if n == 0:
            return 0

        @cache
        def dp(i, color):
            res = costs[i][color]

            if i == n-1:
                pass
            elif color == 0:
                res += min(dp(i+1, 1), dp(i+1, 2))
            elif color == 1:
                res += min(dp(i+1, 0), dp(i+1, 2))
            elif color == 2:
                res += min(dp(i+1, 0), dp(i+1,1))
            return res
        
        return min([dp(0, i) for i in range(3)])

# @lc code=end
