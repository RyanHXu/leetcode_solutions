/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// Sliding Window
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int prod = 1, res = 0, left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      prod *= nums[right];
      while (prod >= k) prod /= nums[left++];
      res += right - left + 1;
    }
    return res;
  }
};

// @lc code=end



// https://leetcode.com/problems/subarray-product-less-than-k/solution/
// https://leetcode.com/problems/subarray-product-less-than-k/discuss/869109/C%2B%2B-Sliding-Window-O(N)-%2B-Binary-Search-(NLogN)-Solution
// FIXME:
// Approach #1: Binary Search on Logarithms [Accepted]
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    double logK = log10(k);
    vector<double> prefix(nums.size() + 1, 0.0);
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prefix[i + 1] = prefix[i] + log10(nums[i]);
    }
    for (int i = 0; i < prefix.size(); ++i) {
      auto low =
          lower_bound(prefix.begin() + i + 1, prefix.end(), prefix[i] + logK) -
          prefix.begin();
      res += low - i - 1;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  cout << log10(10) << endl;
  cout << log(10) << endl;
  cout << log10(100) << endl;
  cout << 1e9 << endl;
  cout << 1e-9 << endl;
  cout << 1e2 << endl;
  cout << 1e-2 << endl;
  return 0;
}
