/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

#include "bits/stdc++.h"

using namespace std;

// TODO: recond review

// @lc code=start
class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {

    int R = box.size();
    int C = box[0].size();
    vector<vector<char>> res(C, vector<char>(R, '.'));
    for (int i = 0; i < R; ++i) {
      for (int j = C - 1, k = C - 1; j >= 0; --j) {
        if (box[i][j] !='.'){
            k = box[i][j] == '*' ? j : k;
            res[k--][R - i - 1] = box[i][j];
        }
      }
    }
    return res;
  }
};
// @lc code=end
