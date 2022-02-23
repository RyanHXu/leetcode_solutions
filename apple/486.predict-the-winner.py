#
# @lc app=leetcode id=486 lang=python3
#
# [486] Predict the Winner
#

# @lc code=start
from functools import cache


class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        @cache
        def dp(i, j):
            if i > j:
                return 0
            if i == j:
                return nums[i]
            return max(
                nums[i] - dp(i+1, j),
                nums[j] - dp(i, j-1)
            )

        return dp(0, len(nums)-1) >= 0
# @lc code=end

