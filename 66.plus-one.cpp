/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    int carry = 1;

    while (i >= 0) {
      int sum = carry + digits[i];
      if (sum <= 9) {
        digits[i] = sum;
        carry = 0;
        break;
      } else {
        digits[i] = 0;
        carry = 1;
      }
      --i;
    }
    if (carry > 0) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
// @lc code=end
