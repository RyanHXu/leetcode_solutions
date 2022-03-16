#include "bits/stdc++.h"

using namespace std;

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
      vector<int> dp = vector<int>(capacity + 1, 0);
    for (int c = 1; c < capacity + 1; ++c) {
      if (c >= weights[0]) {
        dp[c] = profits[0];
      }
    }

    for (int i = 1; i < capacity+1; ++i) {
      for (int j = capacity; j > -1; --j) {
        if(j>=weights[i]){
          dp[j] = max(dp[j], profits[i] + dp[j - weights[i]]);
        }
      }
    }
    return dp[capacity];
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