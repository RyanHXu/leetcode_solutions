/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include "bits/stdc++.h"

using namespace std;

// https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ


// at each step, we try to shrink the windows from the begining until sum smalller than target
// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT32_MAX;
    int j = 0;  // j point to start
    int sum = 0;

    // i point to end
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (sum >= target) {
        res = min(res, i - j + 1);
        sum -= nums[j++];
      }
    }

    return res == INT32_MAX ? 0 : res;
  }
};
// @lc code=end
