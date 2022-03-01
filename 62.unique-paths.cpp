/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m,vector<int>(n,1));
        for (int r = 1; r < m; ++r) {
          for (int c = 1; c < n; ++c) {
              table[r][c] = table[r - 1][c] + table[r][c - 1];
          }
        }
        return table[m - 1][n - 1];
    }
};
// @lc code=end

