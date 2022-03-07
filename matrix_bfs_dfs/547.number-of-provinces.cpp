/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// Friend Circles
#include "bits/stdc++.h"

using namespace std;


// @lc code=start
// we can choose using visited table or not
class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      dfs(isConnected, i, n, visited);
      ++count;
    }
    return count;
  }

  void dfs(vector<vector<int>> &isConnected, int curr, int n,
           vector<bool> &visited) {
    if (visited[curr]) {
      return;
    } else {
      visited[curr] = true;
      for (int i = 0; i < n; ++i) {
        if (isConnected[curr][i] && !visited[i]) {
          dfs(isConnected, i, n, visited);
        }
      }
    }
  }
};
// @lc code=end

int main() {
  vector<vector<int>> ivec{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  vector<vector<int>> ivec2{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Solution s;
  cout << s.findCircleNum(ivec) << endl;
  //   cout << s.findCircleNum(ivec2) << endl;
}