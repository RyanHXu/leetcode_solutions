#
# @lc app=leetcode id=1162 lang=python3
#
# [1162] As Far from Land as Possible
#

# @lc code=start
from collections import deque


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        dirs=[(-1,0),(1,0),(0,1),(0,-1)]
        q = deque()
        visited=set()
        R,C=len(grid),len(grid[0])
        

                
        

        
# @lc code=end

