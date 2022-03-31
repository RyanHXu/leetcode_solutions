#
# @lc app=leetcode id=190 lang=python3
#
# [190] Reverse Bits
#

# @lc code=start
class Solution:
    def reverseBits(self, n: int) -> int:
        res, power = 0, 31
        while n:
            res += (n&1)<<power
            n>>=1
            power-=1
        return res
            
        
# @lc code=end


s = Solution()
print(s.reverseBits(0b00000010100101000001111010011100))
