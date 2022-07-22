/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

#include "bits/stdc++.h"

using namespace std;

// sliding windows
// time complexity: O(N)
// space complexity: O(1)
// https://www.educative.io/courses/grokking-the-coding-interview/JPKr0kqLGNP


// @lc code=start

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();

    // case 1
    if (n <= k) return accumulate(nums.begin(), nums.end(), 0.0) / k;

    // case 2
    double res = INT32_MIN;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];

      if (i >= k - 1) {
        res = max(sum / k, res);
        sum -= nums[i + 1 - k];
      }
    }

    return res;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> ivec{4, 0, 4, 3, 3};
  cout << s.findMaxAverage(ivec, 5) << endl;
}