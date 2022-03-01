#
# @lc app=leetcode id=1291 lang=python3
#
# [1291] Sequential Digits
#

# @lc code=start
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:

        sample = "123456789"
        n = 10
        res = []

        for length in range(len(str(low)), len(str(high))+1):
            for start in range(n-length):
                num = int(sample[start:start+length])
                if low <= num <= high:
                    res.append(num)

        return res


# @lc code=end
