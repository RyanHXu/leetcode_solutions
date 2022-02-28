/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include "bits/stdc++.h"

using namespace std;

// NOTE: second review
// @lc code=start
class Solution {
  vector<vector<int>> res;
  vector<int> comb;

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
      backtrack(candidates, target - candidates[i], i);
      comb.pop_back();
    }
  }
};
// @lc code=end
int main() {
  vector<int> ivec{2, 3, 6, 7};
  Solution s;
  s.combinationSum(ivec, 7);
}
