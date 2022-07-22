/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;

    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return m;

        
      if (nums[l] <= nums[m]) { // [l, m] is non-rotated 
        if (nums[l] <= target && target <= nums[m])
          r = m - 1;
        else  
          l = m + 1;
      } else { 
          // [l, m] is rotated, and pivot located in somewhere between (l,m), and implies (m,r] is sorted 
        if (nums[m] <= target && target <= nums[r])
          l = m + 1;
        else
          r = m - 1;
      }
    }
    return -1;
  }
};
// @lc code=end
