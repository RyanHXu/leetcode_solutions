/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// Peak Valley Approach
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int n = prices.size();
    int maxP = 0;
    while (i < n - 1) {
        // find valley first
      while (i < n - 1 && prices[i] >= prices[i + 1]) {
        ++i;
      }
      valley = prices[i];

        // then, find peak 
      while (i < n - 1 && prices[i] <= prices[i + 1]) {
        ++i;
      }
      peak = prices[i];
      maxP += peak - valley;
    }
    return maxP;
  }
};
// @lc code=end

// Simple One Pass
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      if (prices[i] > prices[i - 1]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};