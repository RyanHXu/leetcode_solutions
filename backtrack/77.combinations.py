#
# @lc app=leetcode id=77 lang=python3
#
# [77] Combinations
#

# @lc code=start
from itertools import combinations
from pprint import pprint
from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(first=1, curr=[]):
            # if combination is done
            if len(curr) ==k:
                output.append(curr[:])
            
            for i in range(first,n+1):
                curr.append(i)
                
                backtrack(i+1,curr)
                curr.pop()
                
                
        output = []
        backtrack()
        return output

# @lc code=end

s = Solution()
pprint(s.combine(4,2))


class Solution2:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(combinations(range(1, n+1), k))

