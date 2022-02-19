#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
# TODO: slide window
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        # mp store the curr index + 1 
        mp ={}
        i =0
        
        for j in range(n):
            if s[j] in mp:
                i = max(mp[s[j]],i)
            
            ans = max(ans, j-i+1)
            mp[s[j]] = j+1
        
        return ans          

# @lc code=end
