using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int c = 1; c < capacity + 1; ++c) {
      dp[0][c] = (c / weights[0]) * profits[0];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < capacity + 1; ++j) {
        // exclude the current number
        dp[i][j] = dp[i - 1][j];
        if (weights[i] <= j) {
          // include the current number
          dp[i][j] = max(dp[i][j], profits[i] + dp[i][j - weights[i]]);
        }
      }
    }
    return dp[n - 1][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;
  cout << ks->solveKnapsack({15, 20, 50}, {1, 2, 3}, 5) << endl;

  delete ks;
}