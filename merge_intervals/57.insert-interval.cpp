/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0, n = intervals.size();

    while (i < n && intervals[i][1] < newInterval[0])
      res.push_back(intervals[i++]);


    // merge intersected intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        ++i;
    }

    res.push_back(newInterval);
    while (i < n) res.push_back(intervals[i++]);

    return res;
  }
};
// @lc code=end

class Solution2 {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    if (intervals.empty() || intervals.back()[1] < newInterval[0]) {
      intervals.push_back(newInterval);
      return intervals;
    }

    vector<vector<int>> res;
    int i = 0;
    // insert interval
    for (; i < intervals.size(); ++i) {
      res.push_back(intervals[i]);

      // non-overlap
      if (res.back()[0] > newInterval[1]) {
        res.insert(res.end() - 1, newInterval);
        break;
      }

      // overlap
      if (res.back()[1] >= newInterval[0]) {
        res.back()[1] = max(res.back()[1], newInterval[1]);
        res.back()[0] = min(res.back()[0], newInterval[0]);
        break;
      }
    }
    ++i;

    // merge intervals
    for (; i < intervals.size(); ++i) {
      if (res.back()[1] >= intervals[i][0]) {
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      } else {
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> ivec{1, 2, 3, 4};
  ivec.insert(ivec.end(), 5);
  for (const auto& val : ivec) {
    cout << val << endl;
  }
  return 0;
}
