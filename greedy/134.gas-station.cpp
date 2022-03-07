/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// if the sum of gas >= the sum of cost, you definetly can traveral the circle, otherwise you can't. we only need to track the starting position.
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int total_tank = 0;
    int curr_tank = 0;
    int start_pos = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      if (curr_tank < 0) {
        start_pos = i + 1;
        curr_tank = 0;
      }
    }

    return total_tank >= 0 ? start_pos : -1;
  }
};
// @lc code=end

// FIXME: time exceed
class Solution2 {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    vector<int> helper(n, 0);
    // if gas[i] - cost[i]>=0, you are able to reach i+1 th gas station
    for (int i = 0; i < n; ++i) {
      if (gas[i] - cost[i] < 0) {
        continue;
      }
      int res = 0;
      for (int j = i; j < i + n; ++j) {
        res += gas[j % n] - cost[j % n];
        if (res < 0) {
          break;
        }
      }
      if (res >= 0) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  //   vector<int> gas{1, 2, 3, 4, 5};
  //   vector<int> cost{3, 4, 5, 1, 2};
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  cout << s.canCompleteCircuit(gas, cost) << endl;
}
