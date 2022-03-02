#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
from functools import cache
from typing import List

# TODO: rescond review
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
      def backtrack(p, left, right, parens=[]):
          if left:
              backtrack(p + '(', left-1, right)
          if right > left:
              backtrack(p + ')', left, right-1)
          if not right:
              parens.append(p)
          return parens
      return backtrack('', n, n)
    
# @lc code=end


s = Solution()
print(s.generateParenthesis(3))
