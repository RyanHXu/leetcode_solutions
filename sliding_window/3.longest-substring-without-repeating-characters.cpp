/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include "bits/stdc++.h"

using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
      // m store (curr index) + 1 of c
    unordered_map<char, int> m;
    int n = s.length();
    int left = 0;
    int res = 0;

    for (int right = 0; right < n; ++right) {
      char c = s[right];
      if (m.find(c) != m.end()) {
        left = max(left, m[c]);
      }
      res = max(res, right - left + 1);
      m[c] = right + 1;
    }
    return res;
  }
};
// @lc code=end

class Solution2 {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> chars(128, 0);
    int left = 0, right = 0;
    int res = 0;
    while (right < s.length()) {
      char r = s[right];
      ++chars[r];
      while (chars[r] > 1) {
        char l = s[left];
        --chars[l];
        ++left;
      }

      res = max(res, right - left + 1);
      ++right;
    }
    return res;
  }
};

// brute force
class Solution3 {
public:
  bool checkRepetition(string &s, int l, int r) {
    vector<int> chars(128, 0);

    for (int i = l; i < r + 1; ++i) {
      ++chars[s[i]];
      if (chars[s[i]] > 1) {
        return false;
      }
    }
    return true;
  }
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (checkRepetition(s, i, j)) {
          res = max(res, j - i + 1);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
}