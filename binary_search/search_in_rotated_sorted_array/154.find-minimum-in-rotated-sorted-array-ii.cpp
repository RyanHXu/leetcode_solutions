/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[r])
        // [0,m] is rotated
        l = m + 1;
      else if (nums[m] < nums[r])
        // m on sorted subarray, and m has the potential to be the smallest
        r = m;
      // handle duplicte numbers
      else
        --r;
    }
    return nums[l];
  }
};
// @lc code=end
