#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
from functools import cache


class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        res = [0]*n
        res[0]=nums[0]
        for i in range(1,n):
            res[i] = max(res[i-1]+nums[i],nums[i])
        
        return max(res)

# @lc code=end


# top-down
class Solution2:
    def maxSubArray(self, nums: list[int]) -> int:

        @cache
        def dp(i: int) -> int:
            if i == 0:
                return nums[i]
            return nums[i] + max(0, dp(i-1))

        return max(dp(i) for i in range(len(nums)))


s = Solution()
print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
print(s.maxSubArray([-1]))