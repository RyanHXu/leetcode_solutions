#
# @lc app=leetcode id=994 lang=python3
#
# [994] Rotting Oranges
#

# @lc code=start
from collections import deque
from typing import List

class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:

        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        q = deque() # used to store rotten orange
        rotten = set()
        fresh = set()
        R, C = len(grid), len(grid[0])
        mins=-1


        for r in range(R):
            for c in range(C):
                if grid[r][c] == 2: # rotten
                    rotten.add((r, c))
                    q.append((r, c))
                elif grid[r][c] == 1:  # fresh
                    fresh.add((r, c))
                    # q.append((r, c))
        if not fresh:
            return 0
                    
                    
        while q:
            for i in range(len(q)):
                x,y = q.popleft()
                for dir in dirs:
                    newX,newY = x+dir[0], y+dir[1]
                    if 0<= newX<R and 0<=newY<C \
                        and (newX, newY) in fresh:
                            fresh.remove((newX,newY))
                            rotten.add((newX,newY))
                            q.append((newX,newY))
                            
            
            mins += 1          
        
        if not fresh:
            return mins
        else:
            return -1        


# @lc code=end


s = Solution()
print(s.orangesRotting([[2, 1, 1], [1, 1, 0], [0, 1, 1]]))
print(s.orangesRotting([[2, 1, 1], [0, 1, 1], [1, 0, 1]]))
print(s.orangesRotting([[0,2]]))
