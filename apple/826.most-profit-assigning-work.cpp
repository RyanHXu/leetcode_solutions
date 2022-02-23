/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); ++i) {
      jobs.push_back({difficulty[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int res = 0, i = 0, best = 0;

    for (const auto val : worker) {
      while (i < jobs.size() && val >= jobs[i].first) {
        best = max(best, jobs[i].second);
        ++i;
      }
      res += best;
    }

    return res;
  }
};
// @lc code=end
