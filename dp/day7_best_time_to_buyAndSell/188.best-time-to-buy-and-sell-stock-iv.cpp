/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
#include "bits/stdc++.h"

using namespace std;
// https://www.youtube.com/watch?v=lXRe__YD8JY
// https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/188.Best-Time-to-Buy-and-Sell-Stock-IV/188.Best-Time-to-Buy-and-Sell-Stock-IV.cpp

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(k>= n/2){
            int res = 0;
            for (int i = 1; i < n; ++i) {
              if(prices[i]> prices[i-1]){
                  res += prices[i] - prices[i - 1];
              }
            }
            return res;
        }
        


    }
};
// @lc code=end


