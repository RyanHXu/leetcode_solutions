#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# 1) try all permulation of s1
# 2) sliding window
# @lc code=start
from math import fabs


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        c1 = [0] * 26
        c2 = [0] * 26
        for sub in s1:
            c1[ord(sub) - ord('a')] += 1

        for i in range(n2):
            if i >= n1:
                c2[ord(s2[i-n1]) - ord('a')] -= 1
            c2[ord(s2[i])-ord('a')] += 1
            if c1 == c2:
                return True
            
        return False


# @lc code=end

s = Solution()
s.checkInclusion('abc','abcd')
