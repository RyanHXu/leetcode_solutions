#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

# TODO: for binary search, please understand left, right, and mid
# @lc code=start
from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            m = l + (r-l)//2
            if nums[m] >= nums[m+1]:
                r = m
            else:
                l = m+1
        return l


# @lc code=end

s = Solution()
print(s.findPeakElement([4, 3, 2, 1]))
print(s.findPeakElement([1, 2, 3, 4]))
print(s.findPeakElement([1, 3, 7, 2]))
print(s.findPeakElement([1, 1, 1, 1]))