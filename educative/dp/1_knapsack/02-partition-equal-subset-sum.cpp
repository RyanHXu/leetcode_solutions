/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include "bits/stdc++.h"

using namespace std;

// try all the combination to see if that works

// idea1: we can think this as dfs


// follow up: count the number of subset sum

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int halfSum = sum / 2;
    int n = nums.size();
    // dp[i][j] means it will be ‘true’ if we can make sum ‘s’ from the first
    // ‘i’ numbers.
    vector<bool> dp(halfSum + 1, false);

    dp[0] = true;
    for (const auto &val : nums) {
      for (int i = halfSum; i >= val; --i) {
        dp[i] = dp[i] || dp[i - val];
      }
    }
    return dp[halfSum];
  }
};
// @lc code=end

// button up
class SolutionButtonUp {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int halfSum = sum / 2;
    int n = nums.size();
    // dp[i][j] means it will be ‘true’ if we can make sum ‘s’ from the first
    // ‘i’ numbers.
    vector<vector<bool>> dp(n, vector<bool>(halfSum + 1));

    for (int r = 0; r < n; ++r) {
      dp[r][0] = true;
    }

    for (int c = 1; c < halfSum + 1; ++c) {
      if (c == nums[0]) {
        dp[0][c] = true;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < halfSum + 1; ++j) {
        // exclude the current value
        if (dp[i - 1][j]) {
          dp[i][j] = dp[i - 1][j];
        } else if ( j >= nums[i]) {
          dp[i][j] = dp[i - 1][j - nums[i]];
        }
      }
    }
    return dp[n - 1][halfSum];
  }
};

class SolutionTopDownVec {
  vector<vector<int>> dp;

 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int halfSum = sum / 2;
    dp = vector<vector<int>>(nums.size(), vector<int>(halfSum + 1, -1));

    return canPartitionRec(nums, halfSum, 0);
  }

  bool canPartitionRec(vector<int> &nums, int halfSum, int index) {
    if (halfSum == 0) {
      return true;
    }
    // check halfSum first
    if (halfSum < 0 || index > nums.size() - 1) {
      return false;
    }

    if (dp[index][halfSum] == -1) {
      if (canPartitionRec(nums, halfSum - nums[index], index + 1))
        dp[index][halfSum] = true;
      else
        dp[index][halfSum] = canPartitionRec(nums, halfSum, index + 1);
    }

    return dp[index][halfSum];
  }
};

class SolutionRec {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int halfSum = sum / 2;

    return canPartitionRec(nums, halfSum, 0);
  }

  bool canPartitionRec(vector<int> &nums, int halfSum, int index) {
    if (halfSum == 0) {
      return true;
    }
    // check halfSum first
    if (halfSum < 0 || index > nums.size() - 1) {
      return false;
    }

    if (nums[index] <= halfSum) {
      if (canPartitionRec(nums, halfSum - nums[index], index + 1)) return true;
    }
    return canPartitionRec(nums, halfSum, index + 1);
  }
};

int main() {
  vector<int> ivec{100, 100, 99, 97};
  SolutionTopDownVec s;
  // if (s.canPartition(ivec)) {
  //   cout << "correct" << endl;
  // }

  // ivec = {1, 2, 3, 4};
  ivec = {1, 2, 3, 6};
  if (s.canPartition(ivec)) {
    cout << "correct" << endl;
  }

  // vector<int> ivec{
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  //     100, 100, 99,  97};
}