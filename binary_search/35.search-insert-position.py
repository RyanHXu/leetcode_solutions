#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#


# TODO: understand binary search, l and r
# case 1, target inside nums
# case 2, target outside of nums
# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        l = 0
        r = len(nums)-1
        
        while l<=r:
            m = l +(r-l)//2
            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1
                
        return l
        
# @lc code=end

