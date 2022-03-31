/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include "bits/stdc++.h"

using namespace std;

// https://www.youtube.com/watch?v=kyvGkcXs_rE

// @lc code=start
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    const int R = board.size();
    if (R == 0) return;
    const int C = board[0].size();

    // lambda
    function<void(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= R || y < 0 || y >= C || board[x][y] != 'O') {
        return;
      }
      board[x][y] = 'G';
      dfs(x - 1, y);
      dfs(x + 1, y);
      dfs(x, y + 1);
      dfs(x, y - 1);
    };

    for (int x = 0; x < R; ++x) {
      dfs(x, 0);
      dfs(x, C - 1);
    }

    for (int y = 0; y < C; ++y) {
      dfs(0, y);
      dfs(R - 1, y);
    }

    unordered_map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};

    for (int x = 0; x < R; ++x) {
      for (int y = 0; y < C; ++y) {
        board[x][y] = v[board[x][y]];
      }
    }
  }
};
// @lc code=end

class Solution2 {
  int R, C;

 public:
  void solve(vector<vector<char>>& board) {
    R = board.size();
    if (R == 0) return;
    C = board[0].size();

    for (int x = 0; x < R; ++x) {
      dfs(board, x, 0);
      dfs(board, x, C - 1);
    }

    for (int y = 0; y < C; ++y) {
      dfs(board, 0, y);
      dfs(board, R - 1, y);
    }

    unordered_map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};

    for (int x = 0; x < R; ++x) {
      for (int y = 0; y < C; ++y) {
        board[x][y] = v[board[x][y]];
      }
    }
  }

  void dfs(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || board[x][y] != 'O') return;
    board[x][y] = 'G';
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
  }
};