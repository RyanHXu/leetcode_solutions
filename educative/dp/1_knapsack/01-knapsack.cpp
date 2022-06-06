#include "bits/stdc++.h"

using namespace std;

// 6 approaches
// dp 1 row 1d array
// dp 2 rows 1d array
// dp 2d array dp
// topdown 2d array
// toddown map
// recursion

// two variables, index of profits, capacity

// 1d array
// final version
class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    // 0,1,2...capacity
    vector<int> dp(capacity + 1, 0);
    for (int i = 1; i < capacity + 1; ++i)
      if (i >= weights[0]) dp[i] = profits[0];

    for (int i = 1; i < n; ++i) {
      for (int j = capacity; j >= 0; --j) {
        if (j >= weights[i]) {
          dp[j] = max(dp[j], profits[i] + dp[j - weights[i]]);
        }
      }
    }
    return dp[capacity];
  }
};

class KnapsackButtonUpOpt {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    // 0,1,2...capacity
    vector<vector<int>> dp(2, vector<int>(capacity + 1, 0));
    for (int i = 1; i < capacity + 1; ++i) {
      if (i >= weights[0]) {
        dp[0][i] = dp[1][i] = profits[0];
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < capacity + 1; ++j) {
        int p1 = 0, p2 = 0;
        if (j >= weights[i]) {
          p1 = profits[i] + dp[(i - 1) % 2][j - weights[i]];
        }
        p2 = dp[(i - 1) % 2][j];

        dp[i % 2][j] = max(p1, p2);
      }
    }
    return max(dp[0][capacity], dp[1][capacity]);
  }
};

class KnapsackButtonUp {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    // 0,1,2...capacity
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i < capacity + 1; ++i) {
      if (i >= weights[0]) {
        dp[0][i] = profits[0];
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < capacity + 1; ++j) {
        int p1 = 0, p2 = 0;
        if (j >= weights[i]) {
          // include the current item
          p1 = profits[i] + dp[i - 1][j - weights[i]];
        }
        // exclude the current item
        p2 = dp[i - 1][j];
        dp[i][j] = max(p1, p2);
      }
    }

    return dp[n - 1][capacity];
  }
};

class KnapsackMap {
  unordered_map<string, int> m;

 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    m = {};
    return solveKnapsackRec(profits, weights, capacity, 0);
  }

  int solveKnapsackRec(const vector<int> &profits, const vector<int> &weights,
                       int capacity, int index) {
    // base check
    if (index > profits.size() - 1 || capacity <= 0) return 0;

    string key = getKey(capacity, index);
    if (!m.count(key)) {
      int p1 = 0, p2 = 0;
      // include current item
      if (weights[index] <= capacity) {
        p1 = profits[index] + solveKnapsackRec(profits, weights,
                                               capacity - weights[index],
                                               index + 1);
      }

      // exlude current item
      p2 = solveKnapsackRec(profits, weights, capacity, index + 1);
      m[key] = max(p1, p2);
    }

    return m[key];
  }

  string getKey(int capacity, int index) {
    return to_string(capacity) + "|" + to_string(index);
  }
};

class KnapsackTopDownVec {
  vector<vector<int>> dp;

 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    dp = vector<vector<int>>(profits.size(), vector<int>(capacity + 1, -1));
    return solveKnapsackRec(profits, weights, capacity, 0);
  }

  int solveKnapsackRec(const vector<int> &profits, const vector<int> &weights,
                       int capacity, int index) {
    // base check
    if (index > profits.size() - 1 || capacity <= 0) return 0;

    if (dp[index][capacity] == -1) {
      int p1 = 0, p2 = 0;
      // include current item
      if (weights[index] <= capacity) {
        p1 = profits[index] + solveKnapsackRec(profits, weights,
                                               capacity - weights[index],
                                               index + 1);
      }

      // exlude current item
      p2 = solveKnapsackRec(profits, weights, capacity, index + 1);
      dp[index][capacity] = max(p1, p2);
    }

    // if we have already solved a similar problem, return the result from
    // memory
    return dp[index][capacity];
  }
};

/**
 Given two integer arrays to represent weights and profits of ‘N’ items, we need
 to find a subset of these items which will give us maximum profit such that
 their cumulative weight is not more than a given number ‘C’. Write a function
 that returns the maximum profit. Each item can only be selected once, which
 means either we put an item in the knapsack or skip it.
 *
 */

class KnapsackRec {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    return solveKnapsackRec(profits, weights, capacity, 0);
  }

  int solveKnapsackRec(const vector<int> &profits, const vector<int> &weights,
                       int capacity, int index) {
    if (index > profits.size() - 1 || capacity <= 0) return 0;
    int p1 = 0, p2 = 0;
    // include current item
    if (weights[index] <= capacity)
      p1 = profits[index] + solveKnapsackRec(profits, weights,
                                             capacity - weights[index],
                                             index + 1);

    // exlude current item
    p2 = solveKnapsackRec(profits, weights, capacity, index + 1);

    return max(p1, p2);
  }
};

class KnapsackRecTest {
 public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                    int capacity) {
    int n = profits.size();
    vector<int> dp(capacity + 1, 0);
    // first row
    for (int i = 1; i < capacity; ++i) {
      if (i >= weights[0]) {
        dp[i] = profits[0];
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = capacity; j >= 0; --j) {
        if (j >= weights[i]) {
          dp[j] = max(dp[j], profits[i] + dp[j - weights[i]]);
        }
      }
    }

    return dp[capacity];
  }
};

int main(int argc, char *argv[]) {
  KnapsackRecTest ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  // 22, 17
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}