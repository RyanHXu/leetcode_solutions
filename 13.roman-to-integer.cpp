/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> m{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

    int res = m[s[0]];

    // IV
    // step 1, res = 1
    // step 2, res += 5 -1
    for (int i = 1; i < s.size(); ++i) {
      int prev = m[s[i - 1]];
      int curr = m[s[i]];

      if (prev < curr) {
        res += curr - prev * 2;
      } else {
        res += curr;
      }
    }
    return res;
  }
};
// @lc code=end
