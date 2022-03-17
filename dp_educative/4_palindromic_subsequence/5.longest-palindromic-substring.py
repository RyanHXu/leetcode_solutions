#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        def getLen(l,r):
            while l>=0 and r<n and s[l] == s[r]:
                l-=1
                r+=1
            return r-l-1
        
        start=0
        length =0
        
        for i in range(n):
            curr = max(getLen(i,i),getLen(i,i+1))
            
            if curr > length:
                length = curr
                # TODO: second review it
                start = i -(curr-1)//2
                
        return s[start: start+length]
        
# @lc code=end

