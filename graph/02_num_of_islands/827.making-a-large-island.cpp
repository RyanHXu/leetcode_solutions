/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

#include "bits/stdc++.h"

using namespace std;

// https://zxi.mytechroad.com/blog/graph/leetcode-827-making-a-large-island/
// NOTE:
// 1) count connected component
// 2) traversal all the water nodes, and sum of all its neighbors

// @lc code=start
class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    color_ = 1;
    g_ = &grid;
    R = grid.size();
    C = grid[0].size();
    unordered_map<int, int> areas;  // color -> area
    int ans = 0;
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (grid[i][j] == 1) {
          ++color_;
          areas[color_] = getArea(i, j);
          ans = max(ans, areas[color_]);
        }
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (grid[i][j] == 0) {
          int area = 1;
          for (int color : set<int>{getColor(i, j - 1), getColor(i, j + 1),
                                    getColor(i - 1, j), getColor(i + 1, j)})
            area += areas[color];
          ans = max(ans, area);
        }
    return ans;
  }

 private:
  int R;
  int C;
  int color_;
  vector<vector<int>>* g_;  // does not own the object.

  int getColor(int x, int y) {
    return (x < 0 || x >= R || y < 0 || y >= C) ? 0 : (*g_)[x][y];
  }

  // Return the area of a connected component, set all elements to color_.
  int getArea(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || (*g_)[x][y] != 1) return 0;
    (*g_)[x][y] = color_;
    return 1 + getArea(x - 1, y) + getArea(x + 1, y) + getArea(x, y - 1) +
           getArea(x, y + 1);
  }
};

// @lc code=end
