/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1) {
      return matrix[0][0];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == 0) {
          matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
        } else if (j == n - 1) {
          matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
        } else {
          auto t = {matrix[i - 1][j - 1], matrix[i - 1][j],
                    matrix[i - 1][j + 1]};
          matrix[i][j] += *min_element(t.begin(), t.end());
        }
      }
    }
    return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
  }
};
// @lc code=end

int main() {
  vector<vector<int>> mat1{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  // 13
  vector<vector<int>> mat2{{-19, 57}, {-40, -5}};
  vector<vector<int>> mat3{{100, -42, -46, -41},
                           {31, 97, 10, -10},
                           {-58, -51, 82, 89},
                           {51, 81, 69, -51}};
  Solution s;
  cout << s.minFallingPathSum(mat1) << endl;
  cout << s.minFallingPathSum(mat2) << endl;
  cout << s.minFallingPathSum(mat3) << endl;
}