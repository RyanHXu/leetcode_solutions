/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include "bits/stdc++.h"

using namespace std;

// TODO: topdown with vector
// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/1801359/c%2B%2B-dptop-down

// @lc code=start
// topdown with map
class Solution {

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
// @lc code=end



// topdown with vector
class Solution2 {

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
