#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        
        # corner case
        if l==r:
            return nums[0]
        
        if nums[l]<nums[r]:
            return nums[l]
        
        while l<=r:
            pivot = l + (r-l)//2
            if nums[pivot] > nums[pivot+1]:
                return nums[pivot+1]
            
            else:
                if nums[l] > nums[pivot]:
                    r = pivot -1
                else:
                    l = pivot +1
        return -1
    
        
# @lc code=end

