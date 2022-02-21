#
# @lc app=leetcode id=784 lang=python3
#
# [784] Letter Case Permutation
#

# @lc code=start
from curses.ascii import isupper


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        res =[]
        
        def backtrack(sub="",i=0):
            if len(sub) == len(s):
                res.append(sub)
            else:
                if s[i].isalpha():
                    backtrack(sub+s[i].swapcase(),i+1)
                backtrack(sub+s[i],i+1)
                
        backtrack()
        
        return res
                
            
        
# @lc code=end

