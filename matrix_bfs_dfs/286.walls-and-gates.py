#
# @lc app=leetcode id=286 lang=python3
#
# [286] Walls and Gates
#

# @lc code=start
from collections import deque


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        q = deque()  # used to store rotten orange
        visited = set()
        walls = set()
        R, C = len(rooms), len(rooms[0])

        for r in range(R):
            for c in range(C):
                if rooms[r][c] == 0:
                    visited.add((r, c)) # gate
                    q.append((r, c))
                if rooms[r][c] == -1: # wall
                    walls.add((r, c))

        if not visited:
            return rooms

        while q:
            for i in range(len(q)):
                x, y = q.popleft()
                for dir in dirs:
                    newX, newY = x+dir[0], y+dir[1]
                    if 0 <= newX < R and 0 <= newY < C \
                        and (newX, newY) not in visited\
                        and (newX, newY) not in walls:
                            rooms[newX][newY] = rooms[x][y]+1
                            visited.add((newX,newY))
                            q.append((newX,newY))
        return rooms

# @lc code=end
