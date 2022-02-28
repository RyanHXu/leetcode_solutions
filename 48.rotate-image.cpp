/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include "bits/stdc++.h"

using namespace std;

// transpose
// reflect

// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    transpose(matrix);
    reflect(matrix);
  }

  void transpose(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int r = 0; r < n; ++r) {
      for (int c = r+1; c < n; ++c) {
        swap(matrix[r][c], matrix[c][r]);
      }
    }
  }

  void reflect(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n / 2; ++c) {
        swap(matrix[r][c], matrix[r][n - c - 1]);
      }
    }
  }
};
// @lc code=end

// observe and find the rule
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < (n + 1) / 2; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        int temp = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
  }
};