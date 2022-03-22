#include "bits/stdc++.h"
// #include "gtest/gtest.h"

using namespace std;

// TODO: this question is pretty similar to subsequence
// for any steps, we have two options
// 1): If the current number is greater than the previous number that we
// included, we can increment our count and make a recursive call for the
// remaining array. 2): We can skip the current number to make a recursive call
// for the remaining arr

// https://leetcode.com/problems/longest-increasing-subsequence/solution/

class LIS {

public:
  int findLISLength(const vector<int> &nums) {
    // reset m
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; ++i) {
      // 0,1...j,i...n-1
      // compare dp[i] with 0...j, +1 if dp[i]
      for (int j = 0; j < i; ++j) {
        // dp[i] <= dp[j]
        if (nums[i] > nums[j] && dp[i]<=dp[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
  }
};

// topdown memo
class LISVec {

  vector<vector<int>> dp;

public:
  int findLISLength(const vector<int> &nums) {
    // reset m
    int n = nums.size();
    dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
    return findLISLengthTopDown(nums, 0, -1);
  }

  int findLISLengthTopDown(const vector<int> &nums, int curr, int prev) {

    // base check
    if (curr == nums.size()) {
      return 0;
    }

    if (dp[curr][prev + 1] == -1) {
      int c1 = 0, c2 = 0;

      // include nums[currentIndex] if it is larger than the last included
      // number
      if (prev == -1 || nums[curr] > nums[prev]) {
        c1 = 1 + findLISLengthTopDown(nums, curr + 1, curr);
      }

      // excluding the number at currentIndex
      c2 = findLISLengthTopDown(nums, curr + 1, prev);

      dp[curr][prev + 1] = max(c1, c2);
    }
    return dp[curr][prev + 1];
  }
};

class LISMap {

  unordered_map<string, int> m;

public:
  int findLISLength(const vector<int> &nums) {
    // reset m
    m = {};
    return findLISLengthTopDown(nums, 0, -1);
  }

  int findLISLengthTopDown(const vector<int> &nums, int curr, int prev) {
    string key = getKey(curr, prev);

    // base check
    if (curr == nums.size()) {
      return 0;
    }

    if (!m.count(key)) {
      int c1 = 0, c2 = 0;

      // include nums[currentIndex] if it is larger than the last included
      // number
      if (prev == -1 || nums[curr] > nums[prev]) {
        c1 = 1 + findLISLengthTopDown(nums, curr + 1, curr);
      }

      // excluding the number at currentIndex
      c2 = findLISLengthTopDown(nums, curr + 1, prev);
      m[key] = max(c1, c2);
    }
    return m[key];
  }

  string getKey(int curr, int prev) {
    return to_string(curr) + "|" + to_string(prev);
  }
};

class LISRecursion {

public:
  int findLISLength(const vector<int> &nums) {
    return findLISLengthRecursive(nums, 0, -1);
  }

  int findLISLengthRecursive(const vector<int> &nums, int curr, int prev) {
    // base check
    if (curr == nums.size()) {
      return 0;
    }

    int c1 = 0, c2 = 0;

    // include nums[currentIndex] if it is larger than the last included number
    if (prev == -1 || nums[curr] > nums[prev]) {
      c1 = 1 + findLISLengthRecursive(nums, curr + 1, curr);
    }

    // excluding the number at currentIndex
    c2 = findLISLengthRecursive(nums, curr + 1, prev);
    return max(c1, c2);
  }
};

// namespace gtest {
// TEST(SolutionTest, CheckSolutionCorrectness) {
//   LIS *lis = new LIS();
//   EXPECT_EQ(5, lis->findLISLength({4, 2, 3, 6, 10, 1, 12}));
//   EXPECT_EQ(4, lis->findLISLength({-4, 10, 3, 7, 15}));
// }
// } // namespace gtest

// int main(int argc, char *argv[]) {
//   ::testing::InitGoogleTest();
//   return RUN_ALL_TESTS();
// }

int main(int argc, char *argv[]) {
  LIS *lis = new LIS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  // 2,3,6,10,12
  cout << lis->findLISLength(nums) << endl; // 5
  nums = vector<int>{-4, 10, 3, 7, 15};
  // -4,3,7,15
  cout << lis->findLISLength(nums) << endl; // 4
  nums = vector<int>{-4, 10, 3, 7, 15, 18, 21};
  // -4,3,7,15,18,21
  cout << lis->findLISLength(nums) << endl; // 6

  nums = vector<int>{-4, 10, 3, 7, 15, 18, -1, 21};
  // -4,3,7,15,18,21
  cout << lis->findLISLength(nums) << endl; // 6
  delete lis;
}
