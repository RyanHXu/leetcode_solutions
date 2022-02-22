#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#

# @lc code=start
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        def binarySearchLeft():
            l, r = 0, len(nums)-1
            while l<=r:
                m = l + (r-l)//2
                if nums[m] < target:
                    l =m+1
                else:
                    r = m-1
            return l

        def binarySearchRight():
            l, r = 0, len(nums)-1
            while l <= r:
                m = l + (r-l)//2
                if nums[m] <= target:
                    l = m+1
                else:
                    r = m-1
            return r
        
        left,right = binarySearchLeft(),binarySearchRight()
        
        return [left,right] if left<=right else [-1,-1]
            
        
        
# @lc code=end

s = Solution()
print(s.searchRange([5, 7, 7, 8, 8, 10], 8))


