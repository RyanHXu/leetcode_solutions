#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#

# @lc code=start
from functools import cache
from re import T

# TODO: second review
# greedy
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        lastPos = n-1
        for i in range(n-1,-1,-1):
            if i + nums[i]>=lastPos:
                lastPos = i
                
        return lastPos ==0


# @lc code=end
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)

        @cache
        def dp(i: int) -> bool:
            """returns whether we can reach n-1 from i"""
            if i >= n-1:
                return True
            if i+nums[i] >= n-1:
                return True
            for s in range(1, nums[i]+1):
                if dp(i+s):
                    return True
            return False

        return dp(0)
