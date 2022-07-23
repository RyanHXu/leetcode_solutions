#include "bits/stdc++.h"

using namespace std;

class TaskSchedulingOrder {
 public:
  static vector<int> findOrder(int tasks,
                               const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> graph;

    // init all non-sink node's degree
    for (const auto& val : prerequisites) {
      inDegree[val[0]] = 0;
    }

    // build graph
    for (const auto& val : prerequisites) {
      int parent = val[0], child = val[1];
      graph[parent].push_back(child);  // put child into parent's list
      ++inDegree[child];
    }

    // put source-nodes into queue
    queue<int> sources;
    for (const auto& val : inDegree) {
      if (val.second == 0) sources.push(val.first);
    }

    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      auto children = graph[vertex];

      for (const auto& child : children) {
        --inDegree[child];
        if (inDegree[child] == 0) sources.push(child);
      }
    }

    if (sortedOrder.size() != tasks) {
      return {};
    }

    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result;

  // topological sort is not possible as the graph has a cycle
  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2},
                             vector<int>{2, 0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5},
                             vector<int>{0, 4}, vector<int>{1, 4},
                             vector<int>{3, 2}, vector<int>{1, 3}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  /**
   *

   0 1 2
   1 0 3 4 2 5
   *
   */
}