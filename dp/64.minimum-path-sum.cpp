/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        // calculate first row
        for (int c = 1; c < C; ++c) {
            grid[0][c] += grid[0][c - 1];
        }
        // calculate first column
        for (int r = 1; r < R; ++r) {
            grid[r][0] += grid[r - 1][0];
        }

        for (int r = 1; r < R; ++r) {
          for (int c = 1; c < C; ++c) {
              grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
          }
        }

        return grid[R - 1][C - 1];
    }
};
// @lc code=end

