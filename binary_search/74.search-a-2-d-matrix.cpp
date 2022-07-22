/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int kR = matrix.size();
    int kC = matrix[0].size();
    int l = 0, r = kR * kC - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        // TODO: //C and %C here, not R
        int num = matrix[m / kC][m % kC];

        if (num == target)
            return true;
        else if (num < target)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
  }
};
// @lc code=end
