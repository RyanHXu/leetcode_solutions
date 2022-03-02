/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// https://www.educative.io/edpresso/the-dutch-national-flag-problem-in-cpp

#include "bits/stdc++.h"

        using namespace std;

// TODO: remember it
// @lc code=start
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int l = 0, m = 0, r = nums.size() - 1;
    while (m <= r) {
      if (nums[m] == 0) {
        swap(nums[m++], nums[l++]);
      } else if (nums[m] == 2) {
        swap(nums[m], nums[r--]);
      } else {
        ++m;
      }
    }
  }
};
// @lc code=end
