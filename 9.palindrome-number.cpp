/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include "bits/stdc++.h"

using namespace std;
// https://leetcode.com/problems/palindrome-number/discuss/1398168/C%2B%2B-Three-Simple-and-Short-Different-Solutions

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    // corner case
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int rev = 0;
    while (x > rev) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }

    // two cases here,
    // when the len is odd
    // when the len is even
    return rev == x || x == rev / 10;
  }
};
// @lc code=end

// convert the number to a string, then use two pointer at beginning and end to
// ehck if it's a palindrome
class Solution {
 public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    int i = 0, j = s.size() - 1;
    while (i < j)
      if (s[i++] != s[j--]) return false;
    return true;
  }
};
// convert the number to a string, revert it and compare
class Solution {
 public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
  }
};