#
# @lc app=leetcode id=417 lang=python3
#
# [417] Pacific Atlantic Water Flow
#

# @lc code=start
from collections import deque
from pprint import pprint
import queue
from typing import List



class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        R, C = len(heights), len(heights[0])
        pacific = set((r, 0) for r in range(R))
        pacific |= set((0, c) for c in range(C))
        atlantic = set((r, C-1) for r in range(R))
        atlantic |= set((R-1, c) for c in range(C))
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        q1 = deque(pacific)
        q2 = deque(atlantic)

        while q1:
            x, y = q1.popleft()
            for dir in dirs:
                newX, newY = x+dir[0], y+dir[1]
                if 0 <= newX < R and 0 <= newY < C \
                        and heights[x][y] <= heights[newX][newY] \
                        and (newX, newY) not in pacific:
                    pacific.add((newX, newY))
                    q1.append((newX, newY))

        while q2:
            x, y = q2.popleft()
            for dir in dirs:
                newX, newY = x+dir[0], y+dir[1]
                if 0 <= newX < R and 0 <= newY < C \
                        and heights[x][y] <= heights[newX][newY] \
                        and (newX, newY) not in atlantic:
                    atlantic.add((newX, newY))
                    q2.append((newX, newY))

        return list(pacific & atlantic)


# @lc code=end

s = Solution()
pprint(s.pacificAtlantic([[1, 2, 3], [8, 9, 4], [7, 6, 5]]))
