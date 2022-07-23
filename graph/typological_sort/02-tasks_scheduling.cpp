#include "bits/stdc++.h"

using namespace std;

class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks,
                                   const vector<vector<int>>& prerequisites) {
    int count = 0;

    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> graph;

    // init all non-sink node's degree
    for (const auto& val : prerequisites) {
      inDegree[val[0]] = 0;
    }

    // update degree,
    // build graph
    for (const auto& val : prerequisites) {
      int parent = val[0], child = val[1];
      graph[parent].push_back(child);
      ++inDegree[child];
    }

    // queue
    queue<int> sources;
    for (const auto& val : inDegree) {
      if (val.second == 0) {
        sources.push(val.first);
      }
    }

    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      ++count;
      auto children = graph[vertex];

      for (const auto& child : children) {
        --inDegree[child];
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    return tasks <= count;
  }
};

int main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  // The tasks have a cyclic dependency, therefore they cannot be scheduled
  result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2},
                             vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5},
                             vector<int>{0, 4}, vector<int>{1, 4},
                             vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}