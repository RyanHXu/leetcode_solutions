#
# @lc app=leetcode id=1137 lang=python3
#
# [1137] N-th Tribonacci Number
#

# @lc code=start
from functools import cache
import re


class Solution:
    @cache
    def tribonacci(self, n: int) -> int:
        if n ==0:
            return 0
        if n<=2:
            return 1
        return self.tribonacci(n-3)+self.tribonacci(n-2)+self.tribonacci(n-1)
# @lc code=end

