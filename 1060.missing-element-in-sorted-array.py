#
# @lc app=leetcode id=1060 lang=python3
#
# [1060] Missing Element in Sorted Array
#

# @lc code=start
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        missing = lambda idx: nums[idx] - nums[0] - idx
        n = len(nums)
        if k > missing(n-1):
            return nums[-1]+k-missing(n-1)
        
        idx =1
        while missing(idx) < k:
            idx+=1
            
        return nums[idx-1]+k-missing(idx-1)
        
# @lc code=end

