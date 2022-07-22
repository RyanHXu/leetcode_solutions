/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include "bits/stdc++.h"

using namespace std;

// https://zxi.mytechroad.com/blog/math/leetcode-69-sqrtx/
// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    int l = 1;
    int r = x;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (m > x / m)
        r = m - 1;
      else
        l = m + 1;
    }
    return r;
  }
};
// @lc code=end

// newton's method
class Solution2 {
public:
    int mySqrt(int a) {
      constexpr double epsilon = 1e-2;
      double x = a;
      while (x * x - a > epsilon) {
        x = (x + a / x) / 2.0;
      }
      return x;
    }
};
