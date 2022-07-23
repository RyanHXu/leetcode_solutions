/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// FIXME:
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> graph;

    if (prerequisites.empty()) return {};

    unordered_set<int> required;

    for (const auto& it : prerequisites) {
      for (const auto& val : it) {
        required.insert(val);
      }
    }

    // init all non-sink node's degree
    for (const auto& val : prerequisites) {
      inDegree[val[1]] = 0;
    }

    // build graph
    for (const auto& val : prerequisites) {
      int parent = val[1], child = val[0];
      graph[parent].push_back(child);
      ++inDegree[child];
    }

    queue<int> sources;
    for (auto& val : inDegree) {
      if (val.second == 0) sources.push(val.first);
    }

    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      auto children = graph[vertex];

      for (auto& child : children) {
        --inDegree[child];
        if (inDegree[child] == 0) sources.push(child);
      }
    }


    return sortedOrder;
  }
};
// @lc code=end
