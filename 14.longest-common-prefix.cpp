/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// NOTE:
// https://leetcode.com/problems/longest-common-prefix/discuss/391089
// time complexity: O(nLog(n))
// space complexity: O(O(1))
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans;
    if (n == 0) return ans;
    sort(strs.begin(), strs.end());
    for (const auto& val : strs) {
      cout << val << endl;
    }
    // a and b are supposed to be the most different among all the pairs of
    // strings in the sorted array
    string a = strs[0];
    string b = strs[1];
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) {
        ans += a[i];
      } else {
        break;
      }
    }
    return ans;
  }
};
// @lc code=end

// horizontal scanning
class Solution2 {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans;
    if (n == 0) return ans;
    string prefix = strs[0];
    for (int i = 1; i < n; ++i) {
      while (strs[i].find(prefix) == string::npos) {
        prefix.pop_back();
        if (prefix.empty()) return "";
      }
    }
    return prefix;
  }
};

int main(int argc, char const* argv[]) {
  // NOTE: horizontal scanning demo
  string str("flight");
  string prefix("flower");
  // NOTE: using != -1 instead of string::npos
  while (str.find(prefix) == string::npos) {
    cout << prefix << endl;
    prefix.pop_back();
  }

  cout << prefix << endl;
  return 0;
}
