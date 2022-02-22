#
# @lc app=leetcode id=1014 lang=python3
#
# [1014] Best Sightseeing Pair
#

# @lc code=start
from functools import cache
from pprint import pprint
from typing import List, Tuple


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        """
        score = (nums[i]+i) + (nums[j]-j)
        """
        @cache
        def dp(j:int)->Tuple[int,int]:
            if j<0: 
                return -10**9, -10**9
            s,v= dp(j-1)
            return max(s,v+values[j]-j),max(v,values[j]+j)
        return dp(len(values)-1)[0]        
        
        
# @lc code=end

s = Solution()

print(s.maxScoreSightseeingPair([8, 1, 5, 2, 6]))

