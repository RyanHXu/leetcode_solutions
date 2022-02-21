#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#

# @lc code=start
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for sub in nums:
            res ^= sub
        return res
            
# @lc code=end


