/*
 * @lc app=leetcode id=1111 lang=cpp
 *
 * [1111] Maximum Nesting Depth of Two Valid Parentheses Strings
 */

// https://www.youtube.com/watch?v=q_53SO8Bz_o

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> res;
    int d = 0;
    for (const auto val : seq) {
      bool open = val == '(';
      if (open) {
        ++d;
      }
      res.push_back(d % 2);
      if (!open) {
        --d;
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  string seq = "(((((())))))";
  Solution s;
  for (const auto val : s.maxDepthAfterSplit(seq)) {
      cout << val << ' ';
  }
  cout << endl;
}
