/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int R, C;
  int numIslands(vector<vector<char>> &grid) {
    R = grid.size(), C = grid[0].size();
    int count = 0;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] == '1') {
          dfs(grid, r, c);
          count += 1;
        }
      }
    }
    return count;
  }

  void dfs(vector<vector<char>> &grid, int r, int c) {
    if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == '1') {
      grid[r][c] = '0';
      dfs(grid, r - 1, c);
      dfs(grid, r + 1, c);
      dfs(grid, r, c - 1);
      dfs(grid, r, c + 1);
    }
  }
};
// @lc code=end
