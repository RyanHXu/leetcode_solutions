#
# @lc app=leetcode id=283 lang=python3
#
# [283] Move Zeroes
#

# @lc code=start
# TODO: track zero index
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        index_of_zero =0
        
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[i],nums[index_of_zero] = nums[index_of_zero],nums[i]
                index_of_zero+=1
        
        
        
# @lc code=end

