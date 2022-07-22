/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 private:
  // <destination, numPassengers>
  typedef pair<int, int> T1;

 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    sort(trips.begin(), trips.end(),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    priority_queue<T1, vector<T1>, greater<>> pq;
    int occupy = 0;
    for (const auto& val : trips) {
      while (!pq.empty() && val[1] >= pq.top().first) {
        occupy -= pq.top().second;
        pq.pop();
      }

      pq.push({val[2], val[0]});
      occupy += val[0];

      if (occupy > capacity) return false;
    }

    return true;
  }
};
// @lc code=end
