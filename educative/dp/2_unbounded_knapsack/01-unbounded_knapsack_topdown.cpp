using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
  vector<vector<int>> dp;
  int n;

  public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
      n = profits.size();
      dp = vector<vector<int>>(n, vector<int>(capacity + 1, 0));
      return solveKnapsackTopDown(profits, weights, capacity);
  }
  int solveKnapsackTopDown(const vector<int> &profits,
                           const vector<int> &weights, int capacity,
                           int index = 0) {
    if (index>n-1 || capacity<=0){
        return 0;
    }

    if(dp[index][capacity]>=0){
      int p1 = 0, p2 = 0;
      if(weights[index] <=capacity){
        p1 = profits[index] + solveKnapsackTopDown(profits, weights, capacity - weights[index], index);
      }
      p2 = solveKnapsackTopDown(profits, weights, capacity, index+1);
      dp[index][capacity] = max(p1, p2);
    }
    return dp[index][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;
  cout << ks->solveKnapsack({15,20,50},{1,2,3} , 5) << endl;

  delete ks;
}