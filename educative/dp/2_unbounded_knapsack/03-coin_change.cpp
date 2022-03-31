#include "bits/stdc++.h"

using namespace std;

class CoinChange {
public:
  int countChange(const vector<int> &denominations, int total) {
    vector<int> dp(total + 1, 1);
    for (int i = 1; i < denominations.size(); ++i) {
      for (int j = denominations[i]; j < total + 1; ++j) {
        dp[j] += dp[j - denominations[i]];
      }
    }
    return dp[total];
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}