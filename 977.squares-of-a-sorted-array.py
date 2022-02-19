#
# @lc app=leetcode id=977 lang=python3
#
# [977] Squares of a Sorted Array
#

# @lc code=start
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n  = len(nums)
        res = [0]*n
        l = 0
        r= n-1
        
        for i in range(n-1,-1,-1):
            if abs(nums[l]) < abs(nums[r]) :
                res[i] = nums[r] **2
                r-=1
                continue
            else:
                res[i] = nums[l]**2
                l+=1
                continue       
        return res
        
        
# @lc code=end


# class Solution:
#     def sortedSquares(self, nums: List[int]) -> List[int]:
#         return [int(x**2) for x in sorted(nums, key=abs)]
