/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

#include "bits/stdc++.h"

using namespace std;

// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-668-kth-smallest-number-in-multiplication-table/

// NOTE: LC378 <= LC668 < LC786
// @lc code=start
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int l = 1, r = m * n+1;
    while (l < r) {
      int x = l + (r - l) / 2;
      if (LEX(m, n, x) >= k)
        r = x;
      else
        l = x + 1;
    }

    return l;
  }
  int LEX(int m, int n, int x) {
    int count = 0;
    for (int i = 1; i <= m; ++i) {
      count += min(n, x / i);
    }
    return count;
  }
};
// @lc code=end

// 59 / 69 test cases passed
class SolutionGenTable {
 public:
  int findKthNumber(int m, int n, int k) {
    vector<int> s(m * n);
    auto it = s.begin();
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        *it++ = i * j;
      }
    }
    // partial sorting
    nth_element(s.begin(), s.begin() + k - 1, s.end());
    return s[k - 1];
  }
};

int main(int argc, char const* argv[]) {
  vector<int> ivec{6, 4, 2, 8, 10, -2, 12, -4, -6};
  nth_element(ivec.begin(), ivec.begin() + ivec.size() / 2, ivec.end());

  // 4
  cout << "median is " << ivec[ivec.size() / 2] << endl;

  // -2 -6 -4 2 4 10 12 8 6
  for (const auto& val : ivec) {
    cout << val << ' ';
  }
  cout << endl;
  return 0;
}
