/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// NOTE:
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/1890199
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;

    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return true;

      if (nums[l] == nums[m] && nums[r] == nums[m]) {
        ++l;
        --r;
      } else if (nums[l] <= nums[m]) {  // [l, m] is non-rotated
        if (nums[l] <= target && target <= nums[m])
          r = m - 1;
        else
          l = m + 1;
      } else {
        // [l, m] is rotated, and pivot located in somewhere between (l,m), and
        // implies (m,r] is sorted
        if (nums[m] <= target && target <= nums[r])
          l = m + 1;
        else
          r = m - 1;
      }
    }
    return false;
  }
};
// @lc code=end
