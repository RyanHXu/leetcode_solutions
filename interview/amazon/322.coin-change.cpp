/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// TODO: brute force
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
      return coinChange(coins, amount, 0);
  }

  int coinChange(vector<int> &coins, int amount, int index) {
    //   if(amount ==0){
    //       return 0;
    //   }
    //   if(index <coins.size() && amount >0){

    //   }
    //   return -1;
  }
};
// @lc code=end

class SolutionButtonUpOpt {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 0; i < coins.size(); ++i) {
      for (int j = 1; j < amount + 1; ++j) {
        if (coins[i] <= j)
          dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

class SolutionButtonUp {
public:
  int coinChange(vector<int> &coins, int amount) {

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

    for (int i = 0; i < n+1; ++i) {
      dp[i][0] = 0;
    }

    for (int i = 1; i < n+1; ++i) {
      for (int j = 1; j < amount + 1; ++j) {
        if (coins[i-1] <= j) {
          dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][amount] > amount ? -1 : dp[n][amount];
  }
};

int main() {
  Solution2 s;
  vector<int> ivec{1, 2, 5};
  cout << s.coinChange(ivec, 11) << endl;

  ivec = {2};
  cout << s.coinChange(ivec, 3) << endl;

  ivec = {1};
  cout << s.coinChange(ivec, 0) << endl;
}