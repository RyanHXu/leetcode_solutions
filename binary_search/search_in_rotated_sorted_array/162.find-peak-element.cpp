/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    // prevent index overflow, l<r instead of l<=r
    while (l < r) { 
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
// @lc code=end
