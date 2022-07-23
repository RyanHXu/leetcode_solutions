/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

#include "bits/stdc++.h"

using namespace std;

// DFS, connected components

// @lc code=start

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> visited;
    dfs(rooms, 0, visited);
    return visited.size() == rooms.size();
  }

  void dfs(vector<vector<int>> &rooms, int curr, unordered_set<int> &visited) {
    // break loop, if traversed curr node before
    if (visited.count(curr))
      return;
    visited.insert(curr);

    for (auto &val : rooms[curr]) {
      dfs(rooms, val, visited);
    }
  }
};

// @lc code=end

