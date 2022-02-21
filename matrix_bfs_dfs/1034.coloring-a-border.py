#
# @lc app=leetcode id=1034 lang=python3
#
# [1034] Coloring A Border
#

# @lc code=start
class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        
        R,C=len(grid),len(grid[0])
        component = set()
        oldColor = grid[row][col]
        def dfs(r: int, c:int):
            if 0<= r<R and 0<=c<C and grid[r][c] ==oldColor:
                
                if grid[r][c] != grid[r-1][c]:
                    grid[r][c] =color
        
                dfs(r-1,c)
                dfs(r+1,c)
                dfs(r,c+1)
                dfs(r,c-1)
                
            
        
        
# @lc code=end


