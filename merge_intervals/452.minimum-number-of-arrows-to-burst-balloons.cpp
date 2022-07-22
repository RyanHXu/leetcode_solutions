/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    int num_arrow = 1;
    int first_end = points[0][1];
    for (const auto& val : points) {
      if (val[0] <= first_end) {
        continue;
      } else {
        first_end = val[1];
        ++num_arrow;
      }
    }
    return num_arrow;
  }
};
// @lc code=end
