/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    set<pair<int, int>> s;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (!matrix[i][j]) {
          s.insert({i, -1});
          s.insert({-1, j});
        }
      }
    }

    for (const auto& val : s) {
        // if val.first != -1 which means we need to set all the column to 0
        if (val.first != -1) {
            for (int i = 0; i < c; ++i) {
                matrix[val.first][i] = 0;
            }
        } else if (val.second != -1) {
            for (int i = 0; i < r; ++i) {
                matrix[i][val.second] = 0;
            }
        }
    }
  }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
}