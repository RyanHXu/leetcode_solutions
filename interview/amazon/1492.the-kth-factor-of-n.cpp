/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// Math way, logN
class Solution {
public:
  int kthFactor(int n, int k) {
    vector<int> divisors;
    int sqrtN = (int)sqrt(n);
    for (int x = 1; x < sqrtN + 1; ++x) {
      if (n % x == 0) {
        --k;
        divisors.push_back(x);
        if (k == 0) {
          return x;
        }
      }
    }
    if (sqrtN * sqrtN == n) {
      ++k;
    }
    int nDiv = divisors.size();
    return k <= nDiv ? n / divisors[nDiv - k] : -1;
  }
};

// @lc code=end

class Solution2 {
public:
  int kthFactor(int n, int k) {

    vector<int> res;
    for (int x = 1; x < n / 2 + 1; ++x) {
      if (n % x == 0) {
        --k;
        if (k == 0) {
          return x;
        }
      }
    }
    return k == 1 ? n : -1;
  }
};
int main() {
  Solution s;
  cout << s.kthFactor(12, 5) << endl;
}