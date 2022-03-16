using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    vector<int> dp(capacity + 1, 0);
    for (int c = 1; c < capacity + 1; ++c) {
      dp[c] = (c / weights[0]) * profits[0];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = weights[i]; j < capacity + 1; ++j) {
        dp[j] = max(dp[j], profits[i] + dp[j - weights[i]]);
      }
    }
    return dp[capacity];
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