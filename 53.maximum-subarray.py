#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
from functools import cache


class Solution:
    def maxSubArray(self, nums: list[int]) -> int:

        @cache
        def dp(i: int) -> int:
            if i == 0:
                return nums[i]
            return nums[i] + max(0, dp(i-1))

        return max(dp(i) for i in range(len(nums)))

# @lc code=end
