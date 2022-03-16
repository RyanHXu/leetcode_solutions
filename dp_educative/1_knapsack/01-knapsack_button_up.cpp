#include "bits/stdc++.h"

using namespace std;

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
      vector<vector<int>> dp = vector<vector<int>>(profits.size(), vector<int>(capacity + 1, 0));
    for (int c = 1; c < capacity + 1; ++c) {
      if (c >= weights[0]) {
        dp[0][c] = profits[0];
      }
    }

    for (int i = 1; i < profits.size(); ++i) {
      for (int j = 1; j < capacity + 1; ++j) {
        int p1 = 0, p2 = 0;
        if (j >= weights[i]) {
          p1 = profits[i] + dp[i - 1][j - weights[i]];
        }
        p2 = dp[i - 1][j];
        dp[i][j] = max(p1, p2);
      }
    }
    return dp[profits.size() - 1][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}