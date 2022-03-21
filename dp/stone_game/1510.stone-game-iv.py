#
# @lc app=leetcode id=1510 lang=python3
#
# [1510] Stone Game IV
#

# @lc code=start
from functools import cache


class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @cache
        def dp(remain):
            if remain ==0:
                return False
            
            sqrt_root = int(remain**0.5)
            
            for i in range(1,sqrt_root+1):
                # if there is any chance to make the opponent lose the game in the next round,
                # then the current player will win
                if not dp(remain - i*i):
                    return True
                
            return False
            
        return dp(n)
            
# @lc code=end

s = Solution()
print(s.winnerSquareGame(4))

