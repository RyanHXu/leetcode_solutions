#
# @lc app=leetcode id=695 lang=python3
#
# [695] Max Area of Island
#

# @lc code=start


class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        R, C = len(grid), len(grid[0])

        # it's nothing that condition order is also important
        def area(r: int, c: int):
            if 0 <= r < R and 0 <= c < C and grid[r][c] == 1:
                grid[r][c] = 0
                return (1 +
                        area(r+1, c) +
                        area(r-1, c) +
                        area(r, c+1) +
                        area(r, c-1))
            return 0

        return max(area(r, c)
                   for r in range(R)
                   for c in range(C))
# @lc code=end