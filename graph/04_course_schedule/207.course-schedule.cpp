/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
  }
};
// @lc code=end



// NOTE: the num of course in prerequisites might smaller than numCrouses
// we need count the num of required courses
class Solution2 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int count = 0;
    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> graph;

    if (prerequisites.empty()) return true;

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
      ++count;
      auto children = graph[vertex];

      for (auto& child : children) {
        --inDegree[child];
        if (inDegree[child] == 0) sources.push(child);
      }
    }

    return required.size() <= count;
  }
};


int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> ivec{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
  cout << s.canFinish(5, ivec) << endl;
  ;
  return 0;
}
