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
  bool found = false;
  int R;
  int C;

  public:
  bool exist(vector<vector<char>> &board, string word) {
    R = board.size();
    C = board.size();
    
    vector<vector<int>> helper;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (board[r][c] == word[0]) {
          dfs(board, word, r, c, 0);
          if (found) return true; 
        }
      }
    }
    return false;
  }
  void dfs(vector<vector<char>> &board, string word, int currRow, int currCol,
           int currIndex) {
    if(board[currRow][currCol]!= '#'){
      if (currIndex == word.size()) {
        found = true;
      }
      for (int i = 0; i < 4; ++i) {
        int r = currRow + directions[i][0];
        int c = currCol + directions[i][1];
        if (r >= 0 && r < R && c >= 0 && c < C && 
            board[r][c] == word[currIndex])
        {
            board[currRow][currCol] = '#';
            dfs(board, word, r, c, currIndex + 1);
        }
        else
        {
            continue;
        }
      }
    }else{
        return;
    }
    
  }
};
// @lc code=end


