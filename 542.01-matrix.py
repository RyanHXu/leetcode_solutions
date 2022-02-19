#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#


# @lc code=start


from functools import cache
from pprint import pprint


class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:

        R, C = len(mat), len(mat[0])

        def dfs(r: int, c: int):
            if r == -1 or r == R or c == -1 or c == C:
                return 10**5
            if 0 <= r < R and 0 <= c < R:
                if mat[r][c] == 0:
                    return 0
                else:
                    res = [
                        dfs(r-1, c),
                        dfs(r+1, c),
                        dfs(r, c+1),
                        dfs(r, c-1)]
                    return 1+min(res)

        # res = []
        # for r in range(R):
        #     tmp = []
        #     for c in range(C):
        #         tmp.append(dfs(r, c))
        #     res.append(tmp)
        # return res

        return dfs(2, 1)

# @lc code=end


s = Solution()
pprint(s.updateMatrix([[0, 0, 0], [0, 1, 0], [1, 1, 1]]))


# TODO: RecursionError: maximum recursion depth exceeded in comparison
