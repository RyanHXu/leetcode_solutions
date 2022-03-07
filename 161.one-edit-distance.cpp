/*
 * @lc app=leetcode id=161 lang=cpp
 *
 * [161] One Edit Distance
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    bool flag = false;
    int n1 = s.size();
    int n2 = t.size();

    for (int i = 0; i < min(n1, n2); ++i) {
      if (s[i] != t[i]) {
        // replace
        if (n1 == n2) {
          return s.substr(i + 1) == t.substr(i + 1);
        } else if (n1 < n2) {
          // insert or delete
          return s.substr(i) == t.substr(i + 1);
        } else {
          // insert or delete
          return s.substr(i + 1) == t.substr(i);
        }
      }
    }
    // insert or delete
    return abs(n1 - n2) == 1;
  }
};
// @lc code=end
