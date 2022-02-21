/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

#include "algorithm"
#include "iostream"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "vector"

using namespace std;

// @lc code=start
using LL = long long;
class Solution {
  vector<int> next[100];

public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        LL dx = bombs[i][0] - bombs[j][0];
        LL dy = bombs[i][1] - bombs[j][1];
        LL dr = bombs[i][2];
        if (dx * dx + dy * dy <= dr * dr) {
          next[i].push_back(j);
        }
      }
    }
    for (size_t s = 0; s < n; ++s) {
      queue<int> q;
      q.push(s);

      vector<bool> visited(n, false);
      visited[s] = true;

      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto val : next[curr]) {
          if (visited[val])
            continue;
          q.push(val);
          visited[val] = true;
        }
      }
      int count = 0;
      for (size_t i = 0; i < n; ++i) {
        count += visited[i];
      }

      cnt = max(cnt, count);
    }
    return cnt;
  }
};


// @lc code=end
