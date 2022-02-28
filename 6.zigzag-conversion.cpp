/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int n = s.size();
    vector<string> rows(min(numRows,n));
    int curRow = 0;
    bool goingDown = false;

    for (const auto val : s) {
        rows[curRow] += val;
        if(curRow == 0 || curRow == numRows-1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string res;
    for (const auto val : rows) {
        res += val;
    }
    return res;
  }
};

// @lc code=end

int main() {
  Solution s;
  cout << s.convert("PAYPALISHIRING", 4);
}

// FIXME:
class Solution3 {
public:
  string convert(string s, int numRows) {
    int n = s.size();
    if (n == 1) {
      return s;
    }

    string res;
    int step = numRows - 2;
    int i = 0;
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < n; ++j) {
        int key1 = i + j * (numRows + step);
        if (key1 > n) {
          break;
        }
        res += s[key1];

        if (i > 0 && i < n - 1) {
          int key2 = key1 + (step - j - 1) + (step - j + 1);
          if (key2 >= n) {
            break;
          }
          res += s[key2];
        }
      }
      res += '\n';
    }
    return res;
  }
};