#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
from functools import cache
from typing import Tuple


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """
        return min/max of subarray product ends with nums[i]
        """
        
        @cache
        def dp(i: int) -> Tuple[int, int]:
            if i == 0:
                return nums[i], nums[i]
            low, hi = dp(i-1)

            if nums[i] < 0:
                low, hi = hi, low
            return min(low*nums[i], nums[i]), max(hi*nums[i], nums[i])

        return max(dp(i)[1] for i in range(len(nums)))

# @lc code=end
