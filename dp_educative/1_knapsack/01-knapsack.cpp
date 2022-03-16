#include "bits/stdc++.h"

using namespace std;

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {

    return solveKnapsackRecursion(profits, weights, capacity);
  }

  int solveKnapsackRecursion(const vector<int> &profits,
                             const vector<int> &weights, int capacity,
                             int index = 0) {
    if (index > profits.size() - 1 || capacity <= 0) {
      return 0;
    }
    int p1 = 0, p2 = 0;
    if (capacity >= weights[index]) {
      p1 = profits[index] + solveKnapsackRecursion(profits, weights,
                                                   capacity - weights[index],
                                                   index + 1);
    }

    p2 = solveKnapsackRecursion(profits, weights, capacity, index + 1);
    return max(p1, p2);
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