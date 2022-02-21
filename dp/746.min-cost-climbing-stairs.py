#
# @lc app=leetcode id=746 lang=python3
#
# [746] Min Cost Climbing Stairs
#

# @lc code=start
from functools import cache


class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        
        # for ith step, you can either start ith -1 or ith -2
        @cache
        def dp(i):
            if i<=1:
                return 0
            return min(dp(i-1)+cost[i-1],dp(i-2)+cost[i-2])
        return dp(len(cost))
            
# @lc code=end


