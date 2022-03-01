/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int R = obstacleGrid.size();
    int C = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }
    obstacleGrid[0][0] = 1;

    // first row
    for (int i = 1; i < C; ++i) {
      // return 1 if obstacleGrid[0][i] and obstacleGrid[0][i-1] must be space,
      // otherwise 0
      obstacleGrid[0][i] =
              (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1)
          ? 1
          : 0;
    }

    // first column
    for (int i = 1; i < R; ++i) {
      obstacleGrid[i][0] =
              (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1)
          ? 1
          : 0;
    }

    for (int i = 1; i < R; ++i) {
      for (int j = 1; j < C; ++j) {
        if (obstacleGrid[i][j] == 0) {
          obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        } else {
          obstacleGrid[i][j] = 0;
        }
      }
    }
    return obstacleGrid[R - 1][C - 1];
  }
};
// @lc code=end

int main() {
//   vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> grid{{0,0}};
  Solution s;
  cout << s.uniquePathsWithObstacles(grid) << endl;
}