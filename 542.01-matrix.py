#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#


# @lc code=start

from collections import deque


class Solution:

    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def bfs(node):
            q = deque()
            q.append((node, 0))
            visited = set()
            while q:
                for i in range(len(q)):
                    coor, d = q.popleft()
                    x, y = coor
                    if mat[x][y] == 0:
                        return d
                    for dir in dirs:
                        newX, newY =x+dir[0], y+dir[1]
                        if 0<=newX<len(mat) and 0<=newY< len(mat):
                            if (newX,newY) not in visited:
                                q.append(((newX, newY),d+1))
            return -1
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    d = bfs((i, j))
                    mat[i][j] = d
        
        return mat
        


# @lc code=end


# TODO: RecursionError: maximum recursion depth exceeded in comparison

# class Solution:
#     def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:

#         R, C = len(mat), len(mat[0])

#         def dfs(r: int, c: int):
#             if r == -1 or r == R or c == -1 or c == C:
#                 return 10**5
#             if 0 <= r < R and 0 <= c < R:
#                 if mat[r][c] == 0:
#                     return 0
#                 else:
#                     res = [
#                         dfs(r-1, c),
#                         dfs(r+1, c),
#                         dfs(r, c+1),
#                         dfs(r, c-1)]
#                     return 1+min(res)

#         res = []
#         for r in range(R):
#             tmp = []
#             for c in range(C):
#                 tmp.append(dfs(r, c))
#             res.append(tmp)
#         return res
