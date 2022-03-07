/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int once=0;
    for (const auto &val : nums) {
      once ^= val;
    }
    return once;
  }
};
// @lc code=end
