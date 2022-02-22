#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
from functools import cache


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        """
        1) max profit 
        2) min price
        """
        @cache
        def dp(i: int)->Tuple[int,int]:
            if i<0:
                return 0,10**9
            profit, price = dp(i-1)
            return max(profit,prices[i]-price), min(price,prices[i])
        
        return dp(len(prices)-1)[0]
# @lc code=end

