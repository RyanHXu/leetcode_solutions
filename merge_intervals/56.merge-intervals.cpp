/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include "bits/stdc++.h"

using namespace std;
// time complexity: O(N*logN)
// space complexity: O(N) 

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });
    vector<vector<int>> res{intervals[0]};

    for (int i = 1; i < intervals.size(); ++i) {
      if (res.back()[1] >= intervals[i][0]) {
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      } else {
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};
// @lc code=end
