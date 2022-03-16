#include "bits/stdc++.h"

using namespace std;

class PartitionSet {
public:
  int canPartition(const vector<int> &num) {
    int n = num.size();
    int sum = accumulate(num.begin(), num.end(), 0);
    int halfSum = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(halfSum + 1, false));

    for (int i = 0; i < n; ++i) {
      dp[i][0] = true;
    }

    for (int c = 1; c < halfSum + 1; ++c) {
      if (c == num[0]) {
        dp[0][c] = true;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < halfSum + 1; ++j) {
        if (dp[i - 1][j]) {
          dp[i][j] = dp[i - 1][j];
        } else if (num[i] <= j) {
          dp[i][j] = dp[i - 1][j - num[i]];
        }
      }
    }

    for (int i = halfSum; i > -1; --i) {
      if (dp[n - 1][i]) {
        return abs(sum - i * 2);
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}