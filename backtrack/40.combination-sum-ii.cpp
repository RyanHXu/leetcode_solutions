/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start


// @lc code=end

// FIXME
class Solution {
  vector<vector<int>> res;
  vector<int> comb;

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    backtrack(candidates, target, 0);
    return res;
  }
  void backtrack(vector<int> &candidates, int target, int start) {
    if (target == 0) {
      res.push_back(comb);
      return;
    } else if (target < 0) {
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      comb.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i + 1);
      comb.pop_back();
    }
  }
};