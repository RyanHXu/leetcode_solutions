/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include "bits/stdc++.h"

using namespace std;
// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    
  }
  
};
// @lc code=end



class Solution {
public:
  string longestPalindrome(string s) {
    const int n = s.length();
    auto getlen = [&](int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      return r - l - 1;
    };

    int len = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        // s might have odd length or even lenght palindrome
      int curr = max(getlen(i, i), getlen(i, i + 1));
      if (curr > len) {
        len = curr;
        start = i - (len - 1) / 2;
      }
    }
    return s.substr(start, len);
  }
};