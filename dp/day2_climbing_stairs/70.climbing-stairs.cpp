/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {

public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsTopDown(dp, n);
  }

  int climbStairsTopDown(vector<int> &dp, int n) {
    if (n <= 2) {
      return n;
    }

    if (dp[n] == -1) {
      dp[n] = climbStairsTopDown(dp, n - 1) + climbStairsTopDown(dp, n - 2);
    }
    return dp[n];
  }
};
// @lc code=end

int main() {
  Solution s;
  for (int i = 1; i < 10; ++i) {
    cout << s.climbStairs(i) << endl;
  }
}