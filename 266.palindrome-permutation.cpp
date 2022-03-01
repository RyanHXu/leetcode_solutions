/*
 * @lc app=leetcode id=266 lang=cpp
 *
 * [266] Palindrome Permutation
 */

#include "bits/stdc++.h"

using namespace std;

// set, map, array, brute force
// @lc code=start
class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> m;
    for (const auto val : s) {
      ++m[val];
    }
    int count = 0;
    for (const auto val : m) {
      count += val.second % 2;
    }

    return count <= 1;
  }
};
// @lc code=end

class Solution {
public:
  bool canPermutePalindrome(string s) {
    int count = 0;
    for (int i = 0; i < 128; ++i) {
      int cnt = 0;
      for (int j = 0; j < s.size(); ++j) {
        if (s[j] == i) {
          ++cnt;
        }
      }
      count += cnt % 2;
    }
    return count <= 1;
  }
};