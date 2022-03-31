#include "bits/stdc++.h"

using namespace std;

class MDSS {

public:
  int findMinimumDeletions(const vector<int> &nums) {
    // reset m
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; ++i) {
      // 0,1...j,i...n-1
      // compare dp[i] with 0...j, +1 if dp[i]
      for (int j = 0; j < i; ++j) {
        // dp[i] <= dp[j]
        if (nums[i] > nums[j] && dp[i] <= dp[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxLen = max(maxLen, dp[i]);
    }
    return n - maxLen;
  }
};

int main(int argc, char *argv[]) {
  MDSS *mdss = new MDSS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << mdss->findMinimumDeletions(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << mdss->findMinimumDeletions(nums) << endl;
  nums = vector<int>{3, 2, 1, 0};
  cout << mdss->findMinimumDeletions(nums) << endl;

  delete mdss;
}