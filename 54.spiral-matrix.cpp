/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int kVisited = 101;
    int R = matrix.size();
    int C = matrix[0].size();
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int currDirection = 0;
    int countChangeDirection = 0;
    int row = 0, col = 0;
    vector<int> res({matrix[0][0]});
    matrix[0][0] = kVisited;

    while (countChangeDirection < 2) {
      vector<int> direction = directions[currDirection];
      while (true) {
        if (!(row + direction[0] >= 0 && row + direction[0] < R &&
              col + direction[1] >= 0 && col + direction[1] < C &&
              matrix[row + direction[0]][col + direction[1]] != kVisited)) {
          break;
        }

        countChangeDirection = 0;
        row += direction[0];
        col += direction[1];
        res.push_back(matrix[row][col]);
        matrix[row][col] = kVisited;
      }
      // add 1 here for next direction
      currDirection = (currDirection + 1) % 4;
      ++countChangeDirection;
    }
    return res;
  }
};
// @lc code=end

// set boundaries
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int direction = 1;
    int i = 0, j = -1;
    vector<int> res;
    while (m * n > 0) {
      for (int k = 0; k < n; ++k) {
        j += direction;
        res.push_back(matrix[i][j]);
      }
      --m;
      for (int k = 0; k < m; ++k) {
        i += direction;
        res.push_back(matrix[i][j]);
      }
      --n;
      direction *= -1;
    }
    return res;
  }
};