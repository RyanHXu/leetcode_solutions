#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#

# @lc code=start


from functools import cache


class Solution:
    def rob(self, nums: List[int]) -> int:
        
        @cache
        def dp(i):
            if i<0:
                return 0
            return max(dp(i-2)+nums[i],dp(i-1))
        
        return dp(len(nums)-1)
            
# @lc code=end
