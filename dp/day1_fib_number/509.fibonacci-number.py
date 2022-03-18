#
# @lc app=leetcode id=509 lang=python3
#
# [509] Fibonacci Number
#

# @lc code=start
from functools import cache


class Solution:
    @cache
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        return self.fib(n-1)+self.fib(n-2)
        
# @lc code=end

