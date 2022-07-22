/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  string intToRoman(int num) {
    vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> rom{"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
    string res = "";
    for (int i = 0; i < val.size(); ++i) {
      while (num >= val[i]) {
        res += rom[i];
        num -= val[i];
      }
    }
    return res;
  }
};
// @lc code=end
