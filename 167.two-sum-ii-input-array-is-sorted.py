#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
import re


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers)-1
        while l <r:
            s = numbers[l] + numbers[r]
            if s== target:
                return [l+1,r+1]
            elif s<target:
                l+=1
            else:
                r-=1


# @lc code=end


# class Solution:
#     def twoSum(self, numbers: List[int], target: int) -> List[int]:
#         dic = {}
#         for i, val in enumerate(numbers):
#             if target-val in dic:
#                 return [dic[target-val]+1, i+1]
#             dic[val] = i
