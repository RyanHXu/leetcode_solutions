/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include "bits/stdc++.h"

using namespace std;

// https://www.educative.io/courses/grokking-the-coding-interview/7npk3V3JQNr

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res{{}};
    sort(nums.begin(), nums.end());
    int start, end = 0;
    vector<int> temp;
    for (int i = 0; i < nums.size(); ++i) {
      start = 0;
      if (i > 0 && nums[i] == nums[i - 1]) {
        start = end + 1;
      }
      end = res.size() - 1;
      for (int j = start; j <= end; ++j) {
        temp = res[j];
        temp.push_back(nums[i]);
        res.push_back(temp);
      }
    }
    return res;
  }
};
// @lc code=end
int main() {
  Solution s;
  vector<int> ivec{1, 2, 2};
  s.subsetsWithDup(ivec);
}