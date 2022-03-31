/*
 * @lc app=leetcode id=644 lang=cpp
 *
 * [644] Maximum Average Subarray II
 */

#include "bits/stdc++.h"

using namespace std;
// https://www.youtube.com/watch?v=1ANJ25VijmE

// @lc code=start

// TODO: binary search
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {

  }
};
// @lc code=end



class SolutionSlidingWindows {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double res = INT32_MIN;
    int n = nums.size();
    for (int i = 0; i < n - k + 1; ++i) {
      double sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        if (j - i + 1 >= k) {
          res = max(res, sum / (j - i + 1));
        }
      }
    }
    return res;
  }
};


// TODO: Time Limit Exceeded
// sliding windows
// O(N*N)
class SolutionSlidingWindows2 {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double res = INT32_MIN;
    // accmulate first k-1 items
    double temp = accumulate(nums.begin(), nums.begin() + k - 1, 0.0);

    int n = nums.size();

    if (n <= k) {
      return (temp + nums[n - 1]) / n;
    }
    for (int step = k; step < n; ++step) {
      int t = step == k ? temp : temp + nums[step - 2];
      temp = t;

      for (int i = step - 1; i < n; ++i) {
        t += nums[i];
        res = max(res, t / double(step));
        // cout << t / double(step) << ' ';
        t -= nums[i + 1 - step];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> ivec{1, 12, -5, -6, 50, 3};
  cout << s.findMaxAverage(ivec, 4) << endl;
  ivec = {5};
  cout << s.findMaxAverage(ivec, 1) << endl;
}