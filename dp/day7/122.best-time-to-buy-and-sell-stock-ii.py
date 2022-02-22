#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
from functools import cache


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        @cache
        def dp(i :int):
            if i<0:
                return 0,-10**9
            
            profit, balance = dp(i-1)
            
            return (
                max(profit,balance+prices[i]), # do nothing, sell
                max(balance,profit-prices[i]), # do nothing, buy
            )
            
        return dp(len(prices)-1)[0]
        
# @lc code=end

