#
# @lc app=leetcode id=1140 lang=python3
#
# [1140] Stone Game II
#

# @lc code=start
from functools import cache
from typing import ByteString


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        @cache
        def dp(l, M):
            if l > n-1:
                return 0

            return max(
                [sum(piles[l:(l+i+1)])-dp(l+i+1, max((i+1), M))
                 for i in range(min(M*2, n))]
            )

        return (dp(0, 1) + sum(piles))//2


# @lc code=end
