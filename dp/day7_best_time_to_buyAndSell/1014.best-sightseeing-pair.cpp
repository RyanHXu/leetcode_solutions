/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// max score = (nums[i]+i) + (nums[j]-j)
// similar to stock problem, we cal nums[i]+i on today, cal[i]-i on next day
class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    vector<int> dp1(n, 0); // store nums[i]-i
    vector<int> dp2(n, 0); // store nums[i]+i
    dp2[0] = values[0] + 0;
    for (int i = 1; i < n; ++i) {
      dp1[i] = max(dp2[i - 1] + values[i] - i, dp1[i - 1]);
      dp2[i] = max(values[i] + i, dp2[i - 1]);
    }
    return dp1[n - 1];
  }
};
// @lc code=end

// https://leetcode.com/problems/best-sightseeing-pair/discuss/260850/JavaC%2B%2BPython-One-Pass-O(1)-space

// cur will record the best score that we have met. We iterate each value a in
// the array A, update res by max(res, cur + a)

// max score = (nums[i]+i) + (nums[j]-j)
class Solution2 {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int res = 0, cur = 0, n = values.size();
    for (int i = 0; i < n; ++i) {
      res = max(res, cur + values[i] - i);
      cur = max(cur, values[i] + i);
    }
    return res;
  }
};

class Solution3 {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int res = 0, cur = 0;
    for (const auto &val : values) {
      res = max(res, cur + val);
      cur = max(cur, val) - 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> ivec{8, 1, 5, 2, 6};
  cout << s.maxScoreSightseeingPair(ivec) << endl;
  vector<int> ivec2{8, 1};
  cout << s.maxScoreSightseeingPair(ivec2) << endl;
}