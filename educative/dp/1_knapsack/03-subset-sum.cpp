#include "bits/stdc++.h"

using namespace std;

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    int totalSum = accumulate(num.begin(), num.end(), 0);
    int n = num.size();

    if (totalSum < sum || n == 0) {
      return false;
    }
    vector<bool> dp(sum + 1, false);

    dp[0] = true;
    for (int c = 1; c < sum + 1; ++c) {
      if (num[0] == c) {
        dp[c] = true;
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = sum; j >= num[i]; --j) {
        if (!dp[j]) {
          dp[j] = dp[j - num[i]];
        }
      }
    }
    return dp[sum];
  }
};

class SubsetSumButtonUp {
public:
  bool canPartition(const vector<int> &num, int sum) {
    int totalSum = accumulate(num.begin(), num.end(), 0);
    int n = num.size();

    if (totalSum < sum || n == 0) {
      return false;
    }
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int r = 0; r < n; ++r) {
      dp[r][0] = true;
    }
    for (int c = 1; c < sum + 1; ++c) {
      if (num[0] == c) {
        dp[0][c] = true;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < sum + 1; ++j) {
        // get the sum `s` without number at index
        if (dp[i - 1][j]) {
          dp[i][j] = dp[i - 1][j];
        } else if (num[i] <= j) {
          // TODO: review it
          // include the current number
          dp[i][j] = dp[i - 1][j - num[i]];
        }
      }
    }
    return dp[n - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}