/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include "bits/stdc++.h"

using namespace std;

// TODO: dp, greedy
// https://leetcode.com/problems/non-overlapping-intervals/solution/

// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int removed = 0, prev = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < prev)
        // drop current ending point
        ++removed;
      else
        // update current ending point
        prev = intervals[i][1];
    }
    return removed;
  }
};
// @lc code=end
