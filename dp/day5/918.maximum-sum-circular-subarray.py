#
# @lc app=leetcode id=918 lang=python3
#
# [918] Maximum Sum Circular Subarray
#

# https://www.youtube.com/watch?v=Gk6yWhfzdOc&list=PLLuMmzMTgVK6krji67w8tEAAud71nQQFe&index=3

# @lc code=start
from functools import cache
from typing import List


# TODO: second review
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        """
        max(prefix+suffix)
        => max(sum-mid)
        => sum + maxSub(-arr)
        """
        n = len(nums)

        @cache
        def dp(i: int, sign: int) -> int:
            if i == 0:
                return nums[i]*sign
            return nums[i]*sign + max(0, dp(i-1, sign))

        max_p = max(dp(i, 1) for i in range(n))
        max_n = max(dp(i, -1) for i in range(n))
        print(max_p)
        print(max_n)
        print(max(max_p, sum(nums)+max_n))
        print(sum(nums)+max_n)

        return max_p if max_p < 0 else max(max_p, sum(nums)+max_n)


# @lc code=end
