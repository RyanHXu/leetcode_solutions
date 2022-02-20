#
# @lc app=leetcode id=1162 lang=python3
#
# [1162] As Far from Land as Possible
#

# @lc code=start
from collections import deque
import queue


# bfs
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        q = deque()
        visited = set()
        R, C = len(grid), len(grid[0])
        steps = -1

        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:  # land
                    q.append((r, c))

        # if all cells are land or sea
        if len(q) == R*C or len(q) == 0:
            return -1

        while q:
            for i in range(len(q)):
                x, y = q.popleft()
                visited.add((x, y))
                for dir in dirs:
                    newX, newY = x+dir[0], y+dir[1]
                    if 0 <= newX < R and 0 <= newY < C \
                           and (newX, newY) not in visited:
                        if grid[newX][newY] == 0:
                            q.append((newX,newY))
                            grid[newX][newY] = 1
                            
            steps += 1
            
        return steps


# @lc code=end
