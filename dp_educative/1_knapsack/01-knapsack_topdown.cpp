#include "bits/stdc++.h"

using namespace std;

class Knapsack {
  vector<vector<int>> dp;

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    dp = vector<vector<int>>(profits.size(), vector<int>(capacity + 1, -1));

    return solveKnapsackTopDown(profits, weights, capacity);
  }

  int solveKnapsackTopDown(const vector<int> &profits,
                             const vector<int> &weights, int capacity,
                             int index = 0) {
    if (index > profits.size() - 1 || capacity <= 0) {
      return 0;
    }

    if (dp[index][capacity] != -1) {
      return dp[index][capacity];
    }
    int p1 = 0, p2 = 0;
    if (capacity >= weights[index]) {
      p1 = profits[index] + solveKnapsackTopDown(profits, weights,
                                                   capacity - weights[index],
                                                   index + 1);
    }
    p2 = solveKnapsackTopDown(profits, weights, capacity, index + 1);

    dp[index][capacity] = max(p1, p2);
    return dp[index][capacity];
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