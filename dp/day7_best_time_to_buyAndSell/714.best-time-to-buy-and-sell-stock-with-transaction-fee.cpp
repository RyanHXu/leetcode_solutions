/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// greedy
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int balance = INT32_MIN, profit = 0;
    for (const auto &val : prices) {
      balance = max(balance, profit - val);
      profit = max(profit, balance + val - fee);
    }
    return profit;
  }
};

// @lc code=end

class Solution2 {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int hold = -prices[0], cash = 0;
    for (int i = 1; i < prices.size(); ++i) {
      cash = max(cash, hold + prices[i] - fee);
      hold = max(hold, cash - prices[i]);
    }

    return cash;
  }
};

// FIXME: Peak and valley approach
// 1 10 9 11
// 3
class Solution3 {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    int valley = prices[0];
    int peak = prices[0];
    int i = 0;
    int profit = 0;
    while (i < n - 1) {
      // find valley
      while (i < n - 1 && prices[i] >= prices[i + 1]) {
        ++i;
      }
      // update valley
      valley = prices[i];

      // find peak
      // profit must greater than fee
      while (i < n - 1 && prices[i] <= prices[i + 1]) {
        ++i;
      }

      // update peak
      peak = prices[i];

      profit += peak - valley - fee;
    }
    return profit;
  }
};

int main() {
  Solution s;
  // vector<int> ivec{1,3,7,5,10,3};
  vector<int> ivec{1, 3, 2, 8, 4, 9};

  cout << s.maxProfit(ivec, 2) << endl;
}