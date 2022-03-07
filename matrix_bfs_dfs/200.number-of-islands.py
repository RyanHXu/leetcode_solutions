#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#

# @lc code=start
from pprint import pprint
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        R, C = len(grid), len(grid[0])

        count = 0

        def dfs(r: int, c: int):
            if 0 <= r < R and 0 <= c < C and grid[r][c] == '1':
                grid[r][c] = '0'
                dfs(r-1, c)
                dfs(r+1, c)
                dfs(r, c+1)
                dfs(r, c-1)

        for r in range(R):
            for c in range(C):
                if grid[r][c] == '1':
                    dfs(r, c)
                    count += 1

        return count
# @lc code=end


l = [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]

for sub in l:
    print(sub)