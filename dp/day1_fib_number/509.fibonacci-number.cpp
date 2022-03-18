/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int fib(int n) {
    vector<int> dp(n + 1, -1);
    return fibTopDown(dp, n);
  }

  int fibTopDown(vector<int> &dp, int n) {
    if (n <= 1) {
      return n;
    }

    if (dp[n] == -1) {
      dp[n] = fibTopDown(dp, n - 2) + fibTopDown(dp, n - 1);
    }

    return dp[n];
  }
};
// @lc code=end
