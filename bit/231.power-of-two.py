#
# @lc app=leetcode id=231 lang=python3
#
# [231] Power of Two
#

# @lc code=start
from math import fabs


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # Power of two has just one 1-bit except 0
        if n ==0:
            return False
        return (n & (n-1)) ==0
        
# @lc code=end

