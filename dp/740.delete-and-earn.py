#
# @lc app=leetcode id=740 lang=python3
#
# [740] Delete and Earn
#

# @lc code=start
from functools import cache


class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        houses = [0]*(10**4+1)
        for x in nums:
            houses[x]+=x
            
        @cache
        def dp(i):
            if i<0:
                return 0
            return max(
                houses[i]+dp(i-2),dp(i-1)
            )        
        return dp(len(houses)-1)
        
# @lc code=end


class Solution2:
    def deleteAndEarn(self, nums: list[int]) -> int:
        houses = [0]*(10**4+1)
        for x in nums:
            houses[x] += x

        @cache
        def dp(i):
            if i < 0:
                return 0
            return max(
                houses[i]+dp(i-2), dp(i-1)
            )
        return dp(len(houses)-1)
