/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */
#include "bits/stdc++.h"

using namespace std;

// NOTE:
// https://zxi.mytechroad.com/blog/?s=1475

// @lc code=start

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    stack<int*> s;
    for (auto& val : prices) {
      while (!s.empty() && *s.top() >= val) {
        *s.top() -= val;
        s.pop();
      }
      s.push(&val);
    }
    return prices;
  }
};
// @lc code=end

class SolutionNaive {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (prices[j] <= prices[i]) {
          prices[i] -= prices[j];
          break;
        }
      }
    }
    return prices;
  }
};