#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
from typing import List


# O(n)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        res, l, r = 0, 0, len(height)-1
        while l < r:
            res = max(res, min(height[l], height[r])*(r-l))

            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res


# @lc code=end


# O(n**2)
class Solution2:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        for i in range(0, n-1):
            for j in range(1, n):
                res = max(
                    res, (j-i)*(min(height[i], height[j]))
                )

        return res
