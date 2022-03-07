/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {

public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size();
    if (n < 3) {
      return n;
    }

    int res = 0;
    unordered_map<char, int> m;
    int left = 0, right = 0;
    while (right < n) {
      m[s[right]] = right;
      ++right;

      if (m.size() == 3) {
        int del_idx = INT32_MAX;
        for (const auto &[key, freq] : m) {
          del_idx = min(del_idx, freq);
        }
        m.erase(s[del_idx]);
        left = del_idx + 1;
      }
      res = max(res, right - left);
    }
    return res;
  }
};
// @lc code=end

int main() {
  // map erase elements
  unordered_map<char, int> m;
  m['a'] = 1;
  m['b'] = 1;
  cout << m.size() << endl;
  m.erase(m.find('a'));
  cout << m.size() << endl;
}
