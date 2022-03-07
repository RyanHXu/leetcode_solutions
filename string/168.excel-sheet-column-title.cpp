/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include "bits/stdc++.h"

using namespace std;

// AB->26 * 1 + 2
// BB->26 * 2 + 2
// CB->26 * 3 + 2

// @lc code=start
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber > 0) {
      --columnNumber;
      res += columnNumber % 26 + 'A';
      columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
  };
};

// @lc code=end

int main() { 
    Solution s;
    cout << s.convertToTitle(26*3+2) << endl;

}
