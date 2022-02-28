#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#

# @lc code=start
from typing import List


# Time Limit Exceeded
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        res = 10**9
        for i in range(0, n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    temp = nums[i]+nums[j]+nums[k]
                    if abs(temp-target) < abs(res-target):
                        res = temp
                        
                        
        return res

# @lc code=end

s = Solution()
print(s.threeSumClosest([0, 0, 0], 1))



