/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res(n, -1);

    int step = (2 * k + 1);

    if (n < step) {
      return res;
    }

    // accmulate first k*2 elements
    long long temp = accumulate(nums.begin(), nums.begin() + step - 1, 0LLU);

    for (int i = k; i < n - k; ++i) {
      temp += nums[i + k];
      res[i] = max(res[i], int(temp / step));
      temp -= nums[i - k];
    }

    return res;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> ivec{7, 4, 3, 9, 1, 8, 5, 2, 6};
  // for (const auto& val : s.getAverages(ivec, 3)) {
  //   cout << val << endl;
  // }

  ivec = {1000};
  for (const auto& val : s.getAverages(ivec, 0)) {
    cout << val << endl;
  }
  // 2.1 b
  cout << INT32_MAX << endl;
  // 20 b
  cout << fixed << 2 * pow(10, 10) << endl;
}