#
# @lc app=leetcode id=541 lang=python3
#
# [541] Reverse String II
#

# @lc code=start
# for reversed
# l1=[1,2,3]
# l1[0:10] = reversed(l1[0:10])
# reversed auto shrink the 10 to 3 
class Solution:

    def reverseStr(self, s: str, k: int) -> str:
        a = list(s)
        n = len(s)
        for i in range(0, n, 2*k):
            a[i:i+k] = reversed(a[i:i+k])
        return "".join(a)

# @lc code=end
