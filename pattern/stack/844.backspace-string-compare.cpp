/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include "bits/stdc++.h"

using namespace std;

// NOTE: pop from an empty stack cause error

// @lc code=start


// https://leetcode.com/problems/backspace-string-compare/solution/
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> s2;
    for (auto& val : s) {
      if (val != '#') {
        s1.push(val);
      }

      if (val == '#' && !s1.empty()) {
        s1.pop();
      }
    }

    for (auto& val : t) {
      if (val != '#') {
        s2.push(val);
      }

      if (val == '#' && !s2.empty()) {
        s2.pop();
      }
    }

    // stop early if the two stack are not the same size
    if (s1.size() != s2.size()) return false;

    while (!s1.empty() && !s2.empty()) {
      if (s1.top() == s2.top()) {
        s1.pop();
        s2.pop();
      } else {
        return false;
      }
    }

    return s1.empty() && s2.empty();
  }
};
// @lc code=end


class Solution2 {
 public:
  bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> s2;
    for (auto& val : s) {
      if (val != '#') {
        s1.push(val);
      }

      if (val == '#' && !s1.empty()) {
        s1.pop();
      }
    }

    for (auto& val : t) {
      if (val != '#') {
        s2.push(val);
      }

      if (val == '#' && !s2.empty()) {
        s2.pop();
      }
    }

    // stop early if the two stack are not the same size
    if (s1.size() != s2.size()) return false;

    while (!s1.empty() && !s2.empty()) {
      if (s1.top() == s2.top()) {
        s1.pop();
        s2.pop();
      } else {
        return false;
      }
    }

    return s1.empty() && s2.empty();
  }
};

int main() {
  stack<int> s;
  s.push(1);
  s.push(1);
  s.push(1);
  cout << s.size() << endl;
}
