/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {
    int res = 0;
    int n = height.size();
    int l = 0, r = n - 1;
    while (l < r) {
      res = max(res, min(height[l], height[r]) * (r - l));
      // Accoarding to Cannikin law, 
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }

    return res;
  }
};

// @lc code=end

// brute force
// Time Limit Exceeded
// 53/60 cases passed (N/A)
class Solution {
public:
  int maxArea(vector<int> &height) {
    int res = 0;
    int n = height.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        res = max(res, (j - i) * min(height[i], height[j]));
      }
    }
    return res;
  }
};
