#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#

# @lc code=start
from functools import cache
from typing import List


# button up
# FIXME
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        s= sum(nums)//2
        
        if n ==0 or s != 0:
            return False
        
        grid = [[False for i in range(s+1)] for j in range(n)]
        
        for j in range(s//2+1):
            grid[0][j] = nums[0] == j

        for i in range(1,n):
            for j in range(1,s+1):
                if grid[i-1][j]:
                    grid[i][j] =grid[i-1][j]
                elif j>=nums[i]:
                    grid[i][j] = grid[i-1][j-nums[i]]
                    
        return grid[n-1][s]
                                        

# @lc code=end

s = Solution()
s.canPartition([1, 5, 11, 5])


# top down
class Solution2:
    def canPartition(self, nums: List[int]) -> bool:

        S = sum(nums)
        n = len(nums)
        if S % 2 != 0 or n == 0:
            return False

        grid = [[-1 for i in range(S//2+1)] for j in range(len(nums))]

        def dp(nums, sum, index):
            if sum == 0:
                return True

            if sum < 0:
                return False

            if index > n-1:
                return 0

            #  if we haven't processed a smiliar problem
            if grid[index][sum] == -1:
                if nums[index] <= sum:
                    if dp(nums, sum-nums[index], index+1) == 1:
                        grid[index][sum] = 1
                        return 1
            grid[index][sum] = dp(nums, sum, index+1)
            
            
            return grid[index][sum]

        return True if dp(nums, S//2, 0) == 1 else False
    

# cache
class Solution3:
    def canPartition(self, nums: List[int]) -> bool:

        S = sum(nums)
        n = len(nums)
        if S % 2 != 0 or n == 0:
            return False

        @cache
        def dp(nums, sum, index):
            if sum == 0:
                return True

            if sum < 0:
                return False

            if index > n-1:
                return False

            if nums[index] <= sum:
                if dp(nums, sum-nums[index], index+1):
                    return True

            return dp(nums, sum, index+1)

        return dp(tuple(nums), S//2, 0)