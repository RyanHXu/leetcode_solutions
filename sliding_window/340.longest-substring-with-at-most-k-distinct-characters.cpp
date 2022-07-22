/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    // case 1
    int n = s.length();
    if (n <= k) {
      return n;
    }

    // case 2
    int left = 0, right = 0;
    int res = 0;
    // store right most position
    unordered_map<char, int> m;
    while (right < n) {
      m[s[right++]] = right;
      // ++right;

      if (m.size() == k + 1) {
        int leftmost_index = INT32_MAX;
        for (const auto &[key, rightmost_index] : m) {
          leftmost_index = min(leftmost_index, rightmost_index);
        }
        m.erase(s[leftmost_index]);
        left = leftmost_index + 1;
      }
      res = max(res, right - left);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  string s1("eceba");
  Solution s;
  cout << s.lengthOfLongestSubstringKDistinct(s1, 2) << '\n';
  return 0;
}
