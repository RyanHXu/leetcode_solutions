/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// backtrack
// NOTE: review
class Solution {
  vector<vector<int>> res{};
  vector<int> subset;
  int n, k;

  public:
  vector<vector<int>> subsets(vector<int> &nums) {
    n = nums.size();
    for (k = 0; k < n + 1; ++k) {
        backtrack(nums, subset, 0);
    }

    return res;
  }
  void backtrack(vector<int> &nums, vector<int> &subset, int start) {
    if (subset.size() == k) {
      res.push_back(subset);
    }

    for (int i = start; i < n; ++i) {
      subset.push_back(nums[i]);
      backtrack(nums, subset, i + 1);
      subset.pop_back();
    }
  }
};
// @lc code=end
// BFS
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res{{}};
    for (const auto val : nums) {
      int n = res.size();
      for (int i = 0; i < n; ++i) {
        auto temp = res[i];
        temp.push_back(val);
        res.push_back(temp);
      }
    }
    return res;
  }
};