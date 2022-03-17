#
# @lc app=leetcode id=740 lang=python3
#
# [740] Delete and Earn
#

# @lc code=start
import collections
from functools import cache


# TODO: review
class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        count = collections.Counter(nums)
        prev = None
        avoid = using = 0
        
        # count[key]: frequence of key
        # using: ith
        # avoid: 
        for key in sorted(count):
            if key -1 != prev:
                avoid, using = max(avoid,using), key*count[key]+max(avoid,using)
            else:
                avoid, using = max(avoid,using), key*count[key]+avoid
            prev = key
        return max(avoid,using)
            
        
# @lc code=end


class Solution2:
    def deleteAndEarn(self, nums: list[int]) -> int:
        houses = [0]*(10**4+1)
        for x in nums:
            houses[x] += x

        @cache
        def dp(key):
            if key < 0:
                return 0
            return max(
                houses[key]+dp(key-2), dp(key-1)
            )
        return dp(len(houses)-1)


s = Solution()
print(s.deleteAndEarn([2,2,3,3,3,4]))