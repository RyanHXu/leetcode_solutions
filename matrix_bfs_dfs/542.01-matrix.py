#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#


# @lc code=start

from collections import deque
from pprint import pprint


class Solution:

    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        q = deque()
        R,C=len(mat),len(mat[0])
        visited=set()
        for r in range(R):
            for c in range(C):
                if mat[r][c] == 0:
                    q.append((r,c))
                    visited.add((r,c))
                    
        while q:
            x,y = q.popleft()
            for dir in dirs:
                newX, newY = x+dir[0], y+dir[1]
                if 0<=newX<R and 0<=newY<C\
                    and (newX,newY) not in visited:
                        mat[newX][newY] = mat[x][y]+1
                        visited.add((newX,newY))
                        q.append((newX,newY))
                    
        return mat


# @lc code=end



# NOTE: approach 2 - slow
# class Solution:

#     def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
#         dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
#         R, C = len(mat), len(mat[0])

#         def bfs(r: int, c: int):
#             q = deque()
#             q.append(
#                 ((r, c), 0)
#             )
#             visited = set()
#             while q:
#                 for i in range(len(q)):
#                     coor, d = q.popleft()
#                     x, y = coor
#                     if mat[x][y] == 0:
#                         return d
#                     visited.add(coor)

#                     for dir in dirs:
#                         newX, newY = x+dir[0], y+dir[1]

#                         if 0 <= newX < R and 0 <= newY < C:
#                             if (newX, newY) not in visited:
#                                 q.append(((newX, newY), d+1))
#             return -1

#         for i in range(len(mat)):
#             for j in range(len(mat[0])):
#                 if mat[i][j] == 1:
#                     mat[i][j] = bfs(i, j)
#         return mat
