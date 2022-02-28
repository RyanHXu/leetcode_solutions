/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
  string countAndSay(int n) {
    string res = "1";
    if (n <= 1) {
      return res;
    }

    for (int i = 2; i <= n; ++i) {
      string temp;
      int k = 0;
      int j = 0;
      for (; j < res.size(); ++j) {
        if (res[k] != res[j]) {
          temp += to_string(j - k) + res[k];
          k = j;
        }
      }
      // it's noting that we only have n-1 compare for n distinct elements
      temp += to_string(j - k) + res.back();
      res = temp;
    }
    return res;
  }
};
// @lc code=end

