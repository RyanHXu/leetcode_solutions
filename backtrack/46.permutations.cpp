/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
  vector<vector<int>> res;

public:
  vector<vector<int>> permute(vector<int> &nums) {
    backtrack(nums, nums.size(), 0);
    return res;
  }

  void backtrack(vector<int> comb, int n, int first) {
    if (first == n) {
      res.push_back(comb);
    }

    for (int i = first; i < n; ++i) {
      swap(comb[i], comb[first]);
      backtrack(comb, n, first + 1);
      swap(comb[i], comb[first]);
    }
  }
};
// @lc code=end
