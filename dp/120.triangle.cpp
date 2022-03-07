/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    if (n == 1) {
      return triangle[0][0];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        // most left
        if (j == 0) {
          triangle[i][j] = triangle[i][j]+triangle[i - 1][0];
        } else if (j == i) {
          // most right
          triangle[i][j] = triangle[i][j] + triangle[i-1][j - 1];
        } else {
          triangle[i][j] =
              triangle[i][j] + min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
      }
    }
    return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << s.minimumTotal(triangle) << endl;
}
