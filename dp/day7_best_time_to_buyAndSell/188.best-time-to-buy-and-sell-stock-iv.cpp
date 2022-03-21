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

// i means days, yes means hold stock
// dp[i][yes] = max( dp[i-1][no]+buy, dp[i-1][yes]+hold );
// dp[i][no] =  max( dp[i-1][yes]+sell, dp[i-1][no]+hold );

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();

    if (k >= n / 2) {
      int res = 0;
      for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
          res += prices[i] - prices[i - 1];
        }
      }
      return res;
    }
    vector<int> hold(k + 1, INT16_MIN);
    vector<int> sold(k + 1, INT16_MIN);
    hold[0] = 0;
    sold[0] = 0;

    for (int i = 0; i < n; ++i) {
      auto hold_old = hold;
      auto sold_old = sold;

      for (int j = 1; j <= k; ++j) {
        hold[j] = max(hold_old[j], sold_old[j - 1] - prices[i]);
        sold[j] = max(sold_old[j], hold_old[j] + prices[i]);
      }
    }
    int res = INT32_MIN;
    for (int i = 0; i <= k; ++i) {
      res = max(res, sold[i]);
    }
    return res;
  }
};


// @lc code=end

int main() { cout << INT16_MIN << endl; }