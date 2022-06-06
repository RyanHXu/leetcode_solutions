/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    string left = "([{";
    string right = ")]}";
    unordered_map<char, char> m{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stack;
    for (auto& c : s) {
      // c is either subset of left or other chars
      if (m.count(c) == 0) {
        stack.push(c);
      } else {
        //  if the c is a closing bracket
        char topElement = stack.empty() ? '#' : stack.top();
        stack.pop();

        if (topElement != m[c]) {
          return false;
        }
      }
    }
    return stack.empty();
  }
};
// @lc code=end


// straightforward
class Solution2 {
 public:
  bool isValid(string s) {
    string left = "([{";
    string right = ")]}";
    stack<char> stack;
    for (auto& c : s) {
      // c in left
      if (left.find(c) != string::npos) {
        stack.push(c);
      } else {
        // we already knew c not in left, it MIGHT in right
        if (stack.empty() || stack.top() != left[right.find(c)]) {
          return false;
        } else {
          stack.pop();
        }
      }
    }
    return stack.empty();
  }
};

int main() {
  string s("([{");
  if (s.find('[') != string::npos) {
    cout << "got it" << endl;
  }

  if (s.find('[') != -1) {
    cout << "got it" << endl;
  }
}
