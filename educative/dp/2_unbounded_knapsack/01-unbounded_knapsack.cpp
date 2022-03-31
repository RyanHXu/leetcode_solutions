using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
  int n;

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    n = profits.size();
    return solveKnapsackRecursion(profits, weights, capacity);
  }
  int solveKnapsackRecursion(const vector<int> &profits,
                           const vector<int> &weights, int capacity,
                           int index = 0) {
    if (index>n-1 || capacity<=0){
        return 0;
    }

    int p1 = 0, p2 = 0;
    if(weights[index]<=capacity){
      p1 = profits[index] + solveKnapsackRecursion(profits, weights, capacity - weights[index], index);
    }
    p2 = solveKnapsackRecursion(profits, weights, capacity, index+1);

    return max(p1, p2);
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