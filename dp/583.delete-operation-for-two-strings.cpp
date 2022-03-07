/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// Approach #4 Without using LCS Dynamic Programmming [Accepted]:
// https://www.youtube.com/watch?v=2XDYkFz9uSc
// https://leetcode.com/problems/delete-operation-for-two-strings/solution/
// 5 Approachs
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 0; i < n1 + 1; ++i) {
      for (int j = 0; j < n2 + 1; ++j) {
        if (i == 0 || j == 0)
          dp[i][j] = i + j;
        else if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
      }
    }
    return dp[n1][n2];
  }
};
// @lc code=end
