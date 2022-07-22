/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    --m;
    --n;
    int r = m + n + 1;

    while (m >= 0 && n >= 0)
      if (nums1[m] >= nums2[n])
        nums1[r--] = nums1[m--];
      else
        nums1[r--] = nums2[n--];

    while (n >= 0) nums1[r--] = nums2[n--];
  }
};
// @lc code=end
