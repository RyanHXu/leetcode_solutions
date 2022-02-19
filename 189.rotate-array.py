#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#

#  k might greatr than n, before handle it, do k %=n
# @lc code=start

# TODO: Approach 3: Using Cyclic Replacements
# TODO: revese twice
from audioop import reverse


class Solution:
    
    def reverse(self, nums: list[int],start:int, end:int) -> None:
        while start < end:
            nums[start], nums[end] =nums[end],nums[start]
            start+=1
            end-=1
        
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        self.reverse(nums,0,n-1)
        self.reverse(nums,0,k-1)
        self.reverse(nums,k,n-1)
        
        return nums
        
# @lc code=end

#%%
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        roatead_arr = nums[n-k:]

        for i in range(n-1, -1+k, -1):
            nums[i] = nums[i-k]
        nums[0:k] = roatead_arr

        return nums


