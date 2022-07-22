/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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

// Easiest solution valid for both duplicate and non duplicate
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/1381096
// class Solution {
// public:
//     int findMin(vector<int>& n) {
//         int s=0,l=n.size();
//         int e =l-1;
//         while(s<e){
//             int m = s+(e-s)/2;
//             if(n[m] > n[e]) s=m+1;          // left side has small values
//             (rotated array) else if(n[m] < n[e]) e=m;       // right side has
//             small value (not rotated) else e--;                       // mid
//             value equal to end move towards small
//         }
//         return n[s];
//     }
// };
