/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include "bits/stdc++.h"

using namespace std;

// top down with vector
// top down with map
// button up with vector
// button up with two variables

// @lc code=start
class Solution {
// Initialize two variables, downOne and downTwo, that represent the minimum cost to reach one step and two steps below the current step, respectively. We will start iteration from step 2, which means these variables will initially represent the minimum cost to reach steps 0 and 1, so we will initialize each of them to 0.
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    int downOne = 0;
    int downTwo = 0;
    for (int i = 2; i < n + 1; ++i) {
      int temp = downOne;
      downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
      // update downTwo
      downTwo = temp;
    }
    return downOne;
  }
}; 

// @lc code=end

// button up
class SolutionButtonUp {

public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i < n + 1; ++i) {
      int takeOneStep = dp[i - 1] + cost[i - 1];
      int takeTwoStep = dp[i - 2] + cost[i - 2];
      dp[i] = min(takeOneStep, takeTwoStep);
    }
    return dp.back();
  }
};

class SolutionMap2 {

public:
  unordered_map<int, int> m;

  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    m = {};
    return minCostClimbingStairsTopDown(cost, n);
  }

  int minCostClimbingStairsTopDown(vector<int> &cost, int i) {
    if (i <= 1) {
      return 0;
    }

    if (m.find(i) == m.end()) {
      m[i] = min(cost[i - 1] + minCostClimbingStairsTopDown(cost, i - 1),
                 cost[i - 2] + minCostClimbingStairsTopDown(cost, i - 2));
    }
    return m[i];
  }
};

// topdown with map
class SolutionMap {

public:
  unordered_map<int, int> m;

  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    m = {};
    return min(minCostClimbingStairsTopDown(cost, n - 1),
               minCostClimbingStairsTopDown(cost, n - 2));
  }

  int minCostClimbingStairsTopDown(vector<int> &cost, int i) {
    // for index at 1 and 0
    if (i <= 1) {
      return cost[i];
    }

    if (m.find(i) == m.end()) {
      m[i] = cost[i] + min(minCostClimbingStairsTopDown(cost, i - 1),
                           minCostClimbingStairsTopDown(cost, i - 2));
    }
    return m[i];
  }
};


// TODO: topdown with vector
// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/1801359/c%2B%2B-dptop-down
class SolutionVec {

public:
  vector<int> dp;

  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    dp = vector<int>(n + 1, -1);
    return min(minCostClimbingStairsTopDown(cost, n - 1),
               minCostClimbingStairsTopDown(cost, n - 2));
  }

  int minCostClimbingStairsTopDown(vector<int> &cost, int i) {
    // for index at 1 and 0
    if (i <= 1) {
      return cost[i];
    }

    if (dp[i] == -1) {
      dp[i] = cost[i] + min(minCostClimbingStairsTopDown(cost, i - 1),
                            minCostClimbingStairsTopDown(cost, i - 2));
    }
    return dp[i];
  }
};

int main() {
  Solution s;
  //   vector<int> ivec{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  vector<int> ivec{10, 15, 20};

  cout << s.minCostClimbingStairs(ivec) << endl;
}
