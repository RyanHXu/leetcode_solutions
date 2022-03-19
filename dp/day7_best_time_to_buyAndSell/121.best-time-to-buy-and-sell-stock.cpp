/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int balance = INT32_MIN, profit = 0;
    for (const auto &val : prices) {
      balance = max(balance, -val);
      profit = max(profit, val + balance);
    }

    return profit;
  }
};

// @lc code=end


class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int minPrice = INT32_MAX, maxProfit = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
        // update lowest price
      if (prices[i] < minPrice) {
        minPrice=prices[i];
      } else if (prices[i] - minPrice > maxProfit) {
        // update max profit
        maxProfit = prices[i] - minPrice;
      }
    }
    return maxProfit;
  }
};
int main() {
  Solution s;
  vector<int> ivec{7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(ivec) << endl;
}