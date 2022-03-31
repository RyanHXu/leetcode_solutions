using namespace std;

#include <iostream>
#include <vector>

class RodCutting {

public:
  int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
      vector<int> dp(n + 1, 0);
      for (int i = 1; i < n+1; ++i) {
          dp[i] = (i / lengths[0]) * prices[0];
      }
      for (int i = 1; i < lengths.size(); ++i) {
        for (int j = lengths[i]; j < n+1; ++j) {
            dp[j] = max(dp[j], prices[i] + dp[j - lengths[i]]);
        }
      }

      return dp[n];
  }
};

int main(int argc, char *argv[]) {
  RodCutting *rc = new RodCutting();
  vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = rc->solveRodCutting(lengths, prices, 5);
  cout << maxProfit << endl;

  delete rc;
}