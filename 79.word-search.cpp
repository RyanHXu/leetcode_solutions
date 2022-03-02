/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
  vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int R;
  int C;

public:
  bool exist(vector<vector<char>> &board, string word) {
    R = board.size();
    C = board[0].size();
    if(word.length()> R*C){
      return false;
    }

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (board[r][c] == word[0] && dfs(board, word, r, c, 0))
          return true;
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>> &board, string word, int i, int j, int idx) {

    if (idx == word.length()) {
      return true;
    }
    if (i < 0 || i >= R || j < 0 || 
      j >= C || board[i][j] != word[idx]) {
      return false;
    }
    char c = board[i][j];
    board[i][j] = '#';
    bool flag = false;
    for (int k = 0; k < 4; ++k) {
      flag = flag || dfs(board, word, directions[k][0] + i, directions[k][1] + j, idx + 1);
    }
    board[i][j] = c;
    return flag;
  }
};
// @lc code=end

int main() {
  vector<vector<char>> grid{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word("SEE");
  Solution s;
  s.exist(grid, word);
}