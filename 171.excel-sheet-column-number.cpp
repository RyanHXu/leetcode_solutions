/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// left -> right
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int res = 0;
    int n = columnTitle.size();
    for (int i = 0; i < n; ++i) {
        res *= 26;
        res += (columnTitle[i] - 'A' + 1);
    }
    return res;
  }
};
// @lc code=end

// right -> left
class Solution2 {
public:
  int titleToNumber(string columnTitle) {
    int res = 0;
    int n = columnTitle.size();
    reverse(columnTitle.begin(), columnTitle.end());
    for (int i = 0; i < n; ++i) {
      res += (columnTitle[i] - 'A' + 1) * pow(26, i);
    }
    return res;
  }
};

int main() {
  Solution s;
  string str("ZY");
  cout << s.titleToNumber(str) << endl;
}