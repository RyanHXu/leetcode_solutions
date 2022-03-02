/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
  vector<string> res;
  string comb;

public:
  vector<string> generateParenthesis(int n) {

    backtrack(n, n);
    return res;
  }
  void backtrack(int left, int right) {
    if (left) {
      comb += "(";
      backtrack(left - 1, right);
      comb.pop_back();
    }

    if (right > left) {
      comb += ")";
      backtrack(left, right - 1);
      comb.pop_back();
    }
    if (!right)
      res.push_back(comb);
  }
};
// @lc code=end

int main() {
  Solution s;
  for (const auto val : s.generateParenthesis(3)) {
    cout << val << '\n';
  }

  cout << endl;
}