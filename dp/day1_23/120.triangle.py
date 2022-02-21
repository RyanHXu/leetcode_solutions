#
# @lc app=leetcode id=120 lang=python3
#
# [120] Triangle
#

# @lc code=start
from functools import cache


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @cache
        def dp(i: int)->int:
            if i<0:
                return 0
            return min()
            
        return dp(len(triangle)-1)
# @lc code=end

