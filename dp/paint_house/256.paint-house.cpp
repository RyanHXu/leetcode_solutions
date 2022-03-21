/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
  unordered_map<string, int> m;

public:
  int minCost(vector<vector<int>> &costs) {
    int n = costs.size();
    for (int i = n - 2; i >= 0; --i) {
      costs[i][0] += min(costs[i + 1][1], costs[i + 1][2]);
      costs[i][1] += min(costs[i + 1][0], costs[i + 1][2]);
      costs[i][2] += min(costs[i + 1][0], costs[i + 1][1]);
    }
    return min(costs[0][0], min(costs[0][1], costs[0][2]));
  }
};
// @lc code=end

// O(N)
// O(N)
class SolutionButtonUp {
  unordered_map<string, int> m;

public:
  int minCost(vector<vector<int>> &costs) {
    vector<int> ans = {minCostTopDown(costs, 0), minCostTopDown(costs, 1),
                       minCostTopDown(costs, 2)};

    return *min_element(ans.begin(), ans.end());
  }

  int minCostTopDown(vector<vector<int>> &costs, int color, int index = 0) {
    if (m.find(getKey(index, color)) != m.end()) {
      return m[getKey(index, color)];
    }

    int res = costs[index][color];

    if (index == costs.size() - 1)
      return res;
    else if (color == 0)
      res += min(minCostTopDown(costs, 1, index + 1),
                 minCostTopDown(costs, 2, index + 1));

    else if (color == 1)
      res += min(minCostTopDown(costs, 0, index + 1),
                 minCostTopDown(costs, 2, index + 1));
    else
      res += min(minCostTopDown(costs, 0, index + 1),
                 minCostTopDown(costs, 1, index + 1));

    m[getKey(index, color)] = res;
    return res;
  }

  string getKey(int index, int color) {
    return to_string(index) + "|" + to_string(color);
  }
};

// TODO: Time Limit Exceeded
class SolutionRecursive {
public:
  int minCost(vector<vector<int>> &costs) {
    vector<int> ans = {minCostRecursive(costs, 0), minCostRecursive(costs, 1),
                       minCostRecursive(costs, 2)};

    return *min_element(ans.begin(), ans.end());
  }

  int minCostRecursive(vector<vector<int>> &costs, int color, int index = 0) {
    int res = costs[index][color];

    if (index == costs.size() - 1)
      return res;
    else if (color == 0)
      res += min(minCostRecursive(costs, 1, index + 1),
                 minCostRecursive(costs, 2, index + 1));

    else if (color == 1)
      res += min(minCostRecursive(costs, 0, index + 1),
                 minCostRecursive(costs, 2, index + 1));
    else
      res += min(minCostRecursive(costs, 0, index + 1),
                 minCostRecursive(costs, 1, index + 1));

    return res;
  }
};
int main() {
  Solution s;
  vector<vector<int>> ivec{
      {18, 17, 7},  {20, 19, 4}, {5, 8, 15},   {6, 3, 17},  {7, 6, 6},
      {8, 1, 9},    {1, 11, 19}, {20, 13, 18}, {15, 17, 3}, {16, 20, 15},
      {16, 7, 15},  {15, 3, 12}, {19, 5, 10},  {8, 18, 15}, {2, 16, 17},
      {12, 17, 16}, {10, 8, 16}, {6, 8, 15},   {14, 3, 18}, {15, 18, 2},
      {20, 10, 20}, {4, 18, 4},  {7, 8, 2},    {4, 1, 8},   {8, 13, 20},
      {12, 20, 4}};
  cout << s.minCost(ivec) << endl;
}