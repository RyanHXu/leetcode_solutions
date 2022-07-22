/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) return true;
    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });

    for (int i = 1; i < intervals.size(); ++i)
      if (intervals[i - 1][1] > intervals[i][0]) return false;

    return true;
  }
};
// @lc code=end
