/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include "bits/stdc++.h"

using namespace std;

// https://zxi.mytechroad.com/blog/searching/leetcode-733-flood-fill/

// @lc code=start

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] == newColor) return image;

    int R = image.size(), C = image[0].size();

    dfs(image, sr, sc, R, C, image[sr][sc], newColor);
    return image;
  }

  void dfs(vector<vector<int>>& image, int r, int c, int R, int C, int orgColor,
           int newColor) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    // if image[r][c] == color, it means current node indirect or direct connect
    // to source node
    if (image[r][c] != orgColor) return;
    image[r][c] = newColor;
    dfs(image, r - 1, c, R, C, orgColor, newColor);
    dfs(image, r + 1, c, R, C, orgColor, newColor);
    dfs(image, r, c + 1, R, C, orgColor, newColor);
    dfs(image, r, c - 1, R, C, orgColor, newColor);
  }
};

// @lc code=end

int main(int argc, char const* argv[]) {
  auto greeting = [](string name) { cout << "Hello " + name << endl; };
  greeting("Ryan");

  int a = 10;
  cout << a << endl;
  auto inc = [&]() { ++a; };
  inc();
  cout << a << endl;

  return 0;
}
