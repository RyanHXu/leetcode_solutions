using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

/*
A basic brute-force solution could be to try finding the Longest Decreasing
Subsequences (LDS), starting from every number in both directions. So for every
index ‘i’ in the given array, we will do two things:

1) Find LDS starting from ‘i’ to the end of the array.
2) Find LDS starting from ‘i’ to the beginning of the array.

LBS would be the maximum sum of the above two subsequences.
*/
class LBS {

public:
  int findLBSLength(const vector<int> &nums) {
    int maxLen = 0;
    int n = nums.size();
    // cause prev start from -1, so we require n+1 space
    vector<int> dp(n, 1);
    vector<int> dpRev(n, 1);

    for (int i = 0; i < n; ++i) {
      // 0,1...j,i...n-1
      for (int j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      // 0,1...i,j...n-1
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] > nums[j])
          dpRev[i] = max(dpRev[i], dpRev[j] + 1);
      }
    }
    
    for (int i = 0; i < n; ++i) {
      maxLen = max(maxLen, dp[i] + dpRev[i] - 1);
    }

    return maxLen;
  }
};

class LBSTopDown {
  vector<vector<int>> dp;
  vector<vector<int>> dpRev;

public:
  int findLBSLength(const vector<int> &nums) {
    int maxLen = 0;
    int n = nums.size();
    // cause prev start from -1, so we require n+1 space
    dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
    dpRev = vector<vector<int>>(n, vector<int>(n + 1, -1));

    for (int i = 0; i < n; ++i) {
      int c1 = findLBSLength(nums, i, -1);
      int c2 = findLBSLengthRev(nums, i, -1);
      maxLen = max(maxLen, c1 + c2 - 1);
    }

    return maxLen;
  }

  int findLBSLength(const vector<int> &nums, int curr, int prev) {
    if (curr == nums.size()) {
      return 0;
    }

    if (dp[curr][prev + 1] == -1) {
      int c1 = 0, c2 = 0;
      if (prev == -1 || nums[curr] < nums[prev]) {
        // include nums[curr]
        c1 = 1 + findLBSLength(nums, curr + 1, curr);
      }
      // exclude the number at curr
      c2 = findLBSLength(nums, curr + 1, prev);
      dp[curr][prev + 1] = max(c1, c2);
    }

    return dp[curr][prev + 1];
  }

  int findLBSLengthRev(const vector<int> &nums, int curr, int prev) {
    if (curr < 0) {
      return 0;
    }

    if (dpRev[curr][prev + 1] == -1) {
      int c1 = 0, c2 = 0;
      if (prev == -1 || nums[curr] < nums[prev]) {
        c1 = 1 + findLBSLengthRev(nums, curr - 1, curr);
      }
      c2 = findLBSLengthRev(nums, curr - 1, prev);
      dpRev[curr][prev + 1] = max(c1, c2);
    }

    return dpRev[curr][prev + 1];
  }
};

class LBSRecursive {

public:
  int findLBSLength(const vector<int> &nums) {
    int maxLen = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int c1 = findLBSLength(nums, i, -1);
      int c2 = findLBSLengthRev(nums, i, -1);
      maxLen = max(maxLen, c1 + c2 - 1);
    }

    return maxLen;
  }

  int findLBSLength(const vector<int> &nums, int curr, int prev) {
    if (curr == nums.size()) {
      return 0;
    }
    int c1 = 0, c2 = 0;
    if (prev == -1 || nums[curr] < nums[prev]) {
      // include nums[curr]
      c1 = 1 + findLBSLength(nums, curr + 1, curr);
    }
    // exclude the number at curr
    c2 = findLBSLength(nums, curr + 1, prev);

    return max(c1, c2);
  }

  int findLBSLengthRev(const vector<int> &nums, int curr, int prev) {
    if (curr < 0) {
      return 0;
    }

    int c1 = 0, c2 = 0;
    if (prev == -1 || nums[curr] < nums[prev]) {
      c1 = 1 + findLBSLengthRev(nums, curr - 1, curr);
    }
    c2 = findLBSLengthRev(nums, curr - 1, prev);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LBS *lbs = new LBS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lbs->findLBSLength(nums) << endl;
  nums = vector<int>{4, 2, 5, 9, 7, 6, 10, 3, 1};
  cout << lbs->findLBSLength(nums) << endl;

  delete lbs;
}