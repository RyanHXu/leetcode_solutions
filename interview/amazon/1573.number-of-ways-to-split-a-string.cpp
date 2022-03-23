/*
 * @lc app=leetcode id=1573 lang=cpp
 *
 * [1573] Number of Ways to Split a String
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// https://www.youtube.com/watch?v=gkFKRbkrIws&t=321s
class Solution {
public:
// we must use long long
  int numWays(string s) {
    long long n = s.length();
    long long countOne = count(s.begin(), s.end(), '1');
    if (countOne % 3 != 0) {
      return 0;
    }
    const long long kDivisor = (long long)(pow(10, 9) + 7);
    if (countOne == 0) {
      return ((n - 1) * (n - 2) / 2) % kDivisor;
    }
    countOne /= 3;
    long long l = 0, r = 0, c = 0;
    for (const auto &val : s) {
      if (val == '1') {
        c += 1;
      }
      if (c == countOne) {
        l += 1;
      }
      if (c == countOne * 2) {
        r += 1;
      }
    }
    return (l * r) % kDivisor;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << s.numWays("0000") << endl;
}
