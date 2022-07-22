/*
 * @lc app=leetcode id=1099 lang=cpp
 *
 * [1099] Two Sum Less Than K
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// Binary Search
// binary-search for a complement value k - nums[i], and point to the result-1
// time complexity: O(NLogN)
// space complexity: from O(LogN) to O(N)
// NOTE:
class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int res = -1;
    for (int i = 0; i < nums.size() && nums[i] < k; ++i) {
        // from i+1 to nums.size() find lower_bound of k-nums[i]
      auto j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) -
               nums.begin() - 1;
      if (j > i)
          res = max(res, nums[i] + nums[j]);
    }
    return res;
  }
};
// @lc code=end

// brute force
// time complexity: O(N*N)
// space complexity: O(1)
class SolutionBruteForce {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int res = -1;

    for (int start = 0; start < nums.size() - 1; ++start) {
      for (int end = start + 1; end < nums.size(); ++end) {
        if (nums[start] + nums[end] < k)
          res = max(res, nums[start] + nums[end]);
      }
    }
    return res;
  }
};

// two pointers
// time complexity: O(NLogN)
// space complexity: from O(LogN) to O(N)
class SolutionTwoPointers {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int l = 0, r = nums.size() - 1;
    int res = -1;
    while (l < r) {
      int sum = nums[l] + nums[r];

      if (sum < k) {
        res = max(res, sum);
        ++l;
      } else {
        --r;
      }
    }
    return res;
  }
};