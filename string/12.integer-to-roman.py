#
# @lc app=leetcode id=12 lang=python3
#
# [12] Integer to Roman
#

# @lc code=start
from pprint import pprint


class Solution:
    def intToRoman(self, num: int) -> str:
        val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]


        rom = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        n = len(val)
        res = ""
        
        for i in range(n):
            while num >= val[i]:
                res += rom[i]
                num -= val[i]
                
        return res        
        
# @lc code=end


# NOTE: greedy
class Solution:
    def intToRoman(self, num: int) -> str:
        digits = [
            (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"),
            (90, "XC"), (50, "L"), (40, "XL"), (10, "X"),
            (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
        ]

        roman_digis = []
        for value, symbol in digits:
            if num == 0:
                break
            count, num = divmod(num, value)
            roman_digis.append(symbol*count)

        return "".join(roman_digis)

