#
# @lc app=leetcode id=278 lang=python3
#
# [278] First Bad Version
#

# @lc code=start
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

# 1 2 3 4 5 6 7 8 9
# G G G B B B B B B       G = Good, B = Bad
# l       m       r
# l m   r
#     l r
#     m  

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        r = n

        while l <= r:
            m = l + (r-l)//2

            if isBadVersion(m):
                r = m-1
            else:
                l = m+1

        return l


# @lc code=end
