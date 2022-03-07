/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

#include "bits/stdc++.h"

using namespace std;

// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-871-minimum-number-of-refueling-stops/
// https://www.youtube.com/watch?v=vWTPA5zw24M

// @lc code=start
// priority queue
// greedy
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int curr = startFuel;
    int stops = 0;
    priority_queue<int> q;
    int i = 0;
    int n = stations.size();
    while (true) {
      if (curr >= target) {
        return stops;
      }
      while (i < n && stations[i][0] <= curr)
        q.push(stations[i++][1]);
      if (q.empty()) {
        break;
      }
      curr += q.top();
      q.pop();
      ++stops;
    }
    return -1;
  }
};

// @lc code=end

// dp
// case1
// startFule => 1000
// target => 100
// [[10,60],[20,30],[30,30],[60,40]]
class Solution2 {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    const int n = stations.size();
    // 0 1 2 3 4 5 ... n
    // max distance after j refuels
    vector<long> dp(n + 1, startFuel);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j >= 1; --j) {
        // check if car can reach next station
        if (dp[j - 1] >= stations[i][0]) {
          // it also update the previous record
          dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
        }
      }
    }
    for (int i = 0; i < n + 1; ++i)
      if (dp[i] >= target)
        return i;

    return -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> stations{{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  cout << s.minRefuelStops(100, 1000, stations) << endl;
}
