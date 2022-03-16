#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#
from functools import cache
from locale import currency
from typing import List


# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        S = sum(nums)
        n = len(nums)
        if n == 0 or S % 2 == 1:
            return False

        @cache
        def dp(nums, sum, curIndex):
            if sum == 0:
                return True
            if sum < 0 or curIndex > n-1:
                return False

            # skip impossible condition
            if nums[curIndex] <= sum:
                if dp(nums, sum-nums[curIndex], curIndex+1):
                    return True

            return dp(nums, sum, curIndex+1)

        return dp(tuple(nums), S//2, 0)

# @lc code=end

class Solution_1:
    def canPartition(self, nums: List[int]) -> bool:
        S = sum(nums)
        n = len(nums)
        if n == 0 or S % 2 == 1:
            return False

        @cache
        def dp(nums, sum, curIndex):
            if sum == 0:
                return True
            if sum < 0 or curIndex > n-1:
                return False
            res = dp(nums, sum, curIndex+1) or dp(nums,
                                                  sum-nums[curIndex], curIndex+1)
            return res

        return dp(tuple(nums), S//2, 0)



# top down
class Solution2:
    def canPartition(self, nums: List[int]) -> bool:
        S = sum(nums)
        n = len(nums)
        if S % 2 == 1 or n == 0:
            return False
        grid = [[-1 for i in range(S//2+1)] for j in range(n)]

        def dp(nums, sum, currIndex):
            if sum == 0:
                return True
            if sum < 0:
                return False
            if currIndex > n-1:
                return 0
            # if we have not already processed a similar problem
            if grid[currIndex][sum] == -1:
                # recursive call after choosing the number at the currentIndex
                # if the number at currentIndex exceeds the sum, we shouldn't process this
                if nums[currIndex] <= sum:
                    if dp(nums, sum-nums[currIndex], currIndex+1):
                        grid[currIndex][sum] = 1
                        return 1
            # recursive call after excluding the number at the currentIndex
            grid[currIndex][sum] = dp(nums, sum, currIndex+1)
            return grid[currIndex][sum]

        return True if dp(nums, S//2, 0) == 1 else False


# button up
class Solution3:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        S = sum(nums)

        if n == 0 or S%2 != 0:
            return False

        s = S//2
        grid = [[False for i in range(s+1)] for j in range(n)]
        
        for i in range(0,n):
            grid[i][0] =True
            
        for j in range(1,s//2+1):
            grid[0][j] = nums[0] == j

        for i in range(1, n):
            for j in range(1, s+1):
                # if we can get the sum 'j' without the number at index 'i'
                if grid[i-1][j]:
                    grid[i][j] = grid[i-1][j]
                # else if we can find a subset to get the remaining sum
                elif j >= nums[i]:
                    grid[i][j] = grid[i-1][j-nums[i]]
        # the bottom-right corner will have our answer.
        return grid[n-1][s]