/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// Button Up - Optimize Space
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    // TODO:
    // 0..., curr(n-2), robNext(n-1), robNextPlugOne(n)
    int robNext = nums[n - 1], robNextPlugOne = 0;
    for (int i = n - 1 - 1; i >= 0; --i) {
      int curr = max(robNext, robNextPlugOne + nums[i]);
      robNextPlugOne = robNext;
      robNext = curr;
    }

    return robNext;
  }
};
// @lc code=end

// button up
class SolutionButtonUp {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    vector<int> dp(n + 1, 0);
    dp[n - 1] = nums[n - 1];

    // from the second to the last
    for (int i = n - 1 - 1; i >= 0; --i) {
      dp[i] = max(dp[i + 2] + nums[i], dp[i - 1]);
    }
    return dp[0];
  }
};

// TODO: top down
class SolutionTopDown {
  vector<int> dp;

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    dp = vector<int>(n + 1, -1);
    return robTopDown(0, nums);
  }

  int robTopDown(int i, vector<int> &nums) {
    if (i > nums.size() - 1) {
      return 0;
    }
    if (dp[i] == -1) {
      dp[i] = max(robTopDown(i + 1, nums), nums[i] + robTopDown(i + 2, nums));
    }

    return dp[i];
  }
};

int main() {
  Solution s;
  vector<int> ivec{1, 2, 3, 1};
  cout << s.rob(ivec) << endl;

  vector<int> ivec2{2, 7, 9, 3, 1};
  cout << s.rob(ivec2) << endl;

  vector<int> ivec3{2};
  cout << s.rob(ivec3) << endl;
}