/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int upper =
        upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    int len = nums.size();

    if (lower == len || nums[lower] != target) {
      return vector<int>{-1, -1};
    }

    return {lower, upper};
  }
};
// @lc code=end

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int lower = lower_bound(nums, target);
    int upper = lower_bound(nums, target + 1) - 1;
    if (lower < nums.size() && nums[lower] == target)
      return {lower, upper};
    else
      return {-1, -1};
  }

  // NOTE:
  int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return l;
  }
};

// 1 3 3 3 5