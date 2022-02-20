#
# @lc app=leetcode id=463 lang=python3
#
# [463] Island Perimeter
#

# @lc code=start
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        R,C = len(grid), len(grid[0])   
        perimer = 0
        
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    perimer +=4
                    if r >0 and grid[r-1][c] ==1:
                        perimer -=2
                    if c>0 and grid[r][c-1] == 1:
                        perimer -=2
                    
        return perimer
        
# @lc code=end

