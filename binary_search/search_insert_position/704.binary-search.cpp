/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }
};
// @lc code=end

class SolutionSTL {
 public:
  int search(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target) return -1;

    return it - nums.begin();
  }
};