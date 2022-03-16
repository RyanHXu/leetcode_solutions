/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include "bits/stdc++.h"

using namespace std;

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
    vector<bool> dp(halfSum + 1,false);

    dp[0] = true;
    for (const auto& val : nums) {
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

    for (int c = 1; c < halfSum+1; ++c) {
      if (c == nums[0]) {
        dp[0][c] = true;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < halfSum + 1; ++j) {
          if(dp[i-1][j]){
              dp[i][j] = dp[i - 1][j];
          }else if (nums[i]<=j)
          {
              dp[i][j] = dp[i - 1][j - nums[i]];
          }
      }
    }
    return dp[n - 1][halfSum];
  }
};

class SolutionTopDown {
  vector<vector<int>> dp;

public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    // NOTE: we use int instead of bool, because we want to use 1 or -1 indicate
    // if we processed it before.
    dp = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
    return canPartitionTopDown(nums, sum / 2);
  }

  bool canPartitionTopDown(vector<int> &nums, int halfSum, int index = 0) {
    if (halfSum == 0) {
      return true;
    }
    if (halfSum < 0 || index > nums.size() - 1) {
      return false;
    }

    if (dp[index][halfSum] == -1) {
      if (nums[index] <= halfSum) {
        if (canPartitionTopDown(nums, halfSum - nums[index], index + 1)) {
          dp[index][halfSum] = 1;
          return true;
        }
      }
      dp[index][halfSum] =
          canPartitionTopDown(nums, halfSum, index + 1) ? 1 : 0;
    }

    return dp[index][halfSum] == 1 ? true : false;
  }
};

class SolutionRecursion {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (nums.size() == 0 || sum % 2 == 1) {
      return false;
    }
    return canPartitionRecursion(nums, sum / 2);
  }

  bool canPartitionRecursion(vector<int> &nums, int halfSum, int index = 0) {
    if (halfSum == 0) {
      return true;
    }
    if (halfSum < 0 || index > nums.size() - 1) {
      return false;
    }

    if (nums[index] <= halfSum) {
      if (canPartitionRecursion(nums, halfSum - nums[index], index + 1)) {
        return true;
      }
    }
    return canPartitionRecursion(nums, halfSum, index + 1);
  }
};

int main() {
  vector<int> ivec{
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 99,  97};
  //   vector<int> ivec{100, 100, 99, 97};
  Solution s;
  if (s.canPartition(ivec)) {
    cout << "correct" << endl;
  }
}