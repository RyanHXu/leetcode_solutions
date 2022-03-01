#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
# TODO: slide window

# O(n**3) 
# 1) n to the fifth 
# 2) n to the power of 5


# logarithms

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def check(start ,end):
            chars = [0]*128
            
            for i in range(start, end+1):
                c= s[i];
                chars[ord(c)] +=1
                if chars[ord(c)] > 1:
                    return False
                
            return True
                
        n = len(s)
        res =0
        for i in range(n):
            for j in range(i,n):
                if check(i,j):
                    res = max(res,j-i+1)
                    
        return res

# @lc code=end


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        # mp store the curr index + 1
        mp = {}
        i = 0

        for j in range(n):
            if s[j] in mp:
                i = max(mp[s[j]], i)

            ans = max(ans, j-i+1)
            mp[s[j]] = j+1

        return ans
