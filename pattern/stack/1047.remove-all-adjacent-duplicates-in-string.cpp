/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

#include "bits/stdc++.h"

using namespace std;

// abbba
// TODO: scan from right to left
// stack

// @lc code=start
class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> s1;
    char prev = ' ';

    for (auto& val : s) {
      if (!s1.empty()) {
        if (val == s1.top())
          s1.pop();
        else
          s1.push(val);
      } else {
        s1.push(val);
      }
    }

    string res;
    while (!s1.empty()) {
      res += s1.top();
      s1.pop();
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << s.removeDuplicates("abbaca") << endl;
}