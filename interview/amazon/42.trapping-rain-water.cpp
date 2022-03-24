/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include "bits/stdc++.h"

using namespace std;

// brute force
// dp
// two pointer

// https://www.youtube.com/watch?v=StH5vntauyQ
// @lc code=start

// TODO: two pointers way
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-42-trapping-rain-water/
class Solution{
  public:
  int trap(vector<int>& height){

  }
};

// @lc code=end



// dp O(N)
class Solution2 {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> L(n, 0);
    vector<int> R(n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      // bound check
      L[i] = i == 0 ? height[i] : max(L[i - 1], height[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
      // bound check
      R[i] = i == n - 1 ? height[i] : max(R[i + 1], height[i]);
    }
    for (int i = 0; i < n; ++i) {
      res += min(L[i], R[i]) - height[i];
    }
    return res;
  }
};

// brute force
class Solution3 {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int count = 0;
    auto sit = cbegin(height);
    auto eit = cend(height);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      // max_element [sit, sit+i+1)
      int L = *max_element(sit, sit + i + 1);
      int R = *max_element(sit + i, eit);
      res += min(L, R) - height[i];
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<int> ivec{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(ivec) << endl;
}
