/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include "bits/stdc++.h"

using namespace std;

// bruteforce
// unorder_set, for N/3 * N/3 * 9 + N + N = > N*N

// @lc code=start
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> column(9);
    vector<unordered_set<char>> boxes(9);

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        char key = board[r][c];
        // be careful 
        if(key!='.'){
          if (rows[r].find(key) == rows[r].end()) {
            rows[r].insert(key);
          } else {
            return false;
          }

          if (column[c].find(key) == column[c].end()) {
            column[c].insert(key);
          } else {
            return false;
          }

          int idx = r / 3 * 3 + c / 3;

          if (boxes[idx].find(key) == boxes[idx].end()) {
            boxes[idx].insert(key);
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  s.isValidSudoku(board);
}
