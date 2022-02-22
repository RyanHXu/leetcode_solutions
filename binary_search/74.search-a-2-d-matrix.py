#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#

# @lc code=start
from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        R, C = len(matrix), len(matrix[0])
        l, r = 0, R*C-1

        while l <= r:
            mid = (l+r)//2
            # TODO: //C and %C here, not R
            num = matrix[mid//C][mid % C]

            if num == target:
                return True
            elif num < target:
                l = mid+1
            else:
                r = mid - 1

        return False


# @lc code=end

s = Solution()
print(s.searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3))
