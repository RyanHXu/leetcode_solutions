#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#


# @lc code=start
# TODO: dfs
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        R, C = len(image), len(image[0])
        color = image[sr][sc]
        if color == newColor: return image
        def dfs(r: int, c:int ):
            if image[r][c] == color: 
                image[r][c] = newColor
                if r-1 >=0: dfs(r-1,c)
                if r+1 < R: dfs(r+1,c)
                if c-1 >= 0: dfs(r,c-1)
                if c+1 < C: dfs(r,c+1)
        
        dfs(sr,sc)
        
        return image
        
# @lc code=end

