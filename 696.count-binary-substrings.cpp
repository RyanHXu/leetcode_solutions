/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// linear scan
class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.length();
    int res = 0, prev = 0, curr = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] != s[i]) {
        res += min(prev, curr);
        prev = curr;
        curr = 1;
      } else {
        ++curr;
      }
    }
    return res + min(curr, prev);
  }
};
// @lc code=end

// Group By Character
class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.length();
    vector<int> groups(n, 0);
    groups[0] = 1;
    int indexOfGroups = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] != s[i]) {
        groups[++indexOfGroups] = 1;
      } else {
        ++groups[indexOfGroups];
      }
    }

    int res = 0;
    for (int i = 1; i < indexOfGroups + 1; ++i) {
      res += min(groups[i - 1], groups[i]);
    }

    return res;
  }
};