#
# @lc app=leetcode id=557 lang=python3
#
# [557] Reverse Words in a String III
#

# @lc code=start
class Solution:
    def reverseWords(self, s: str) -> str:
        tmp = s.split(' ')
        res=""
        for sub in tmp:
            # reverse string in python 
            res += sub[::-1] + ' '
        
        return res[:-1]
            
        
        
        
# @lc code=end


# TODO: two pointers
# class Solution:
#     def reverseWords(self, s: str) -> str:
#         res = ''
#         l, r = 0, 0
#         while r < len(s):
#             if s[r] != ' ':
#                 r += 1
#             elif s[r] == ' ':
#                 res += s[l:r + 1][::-1]
#                 r += 1
#                 l = r
#         res += ' '
#         res += s[l:r + 2][::-1]
#         return res[1:]
