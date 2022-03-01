/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include "bits/stdc++.h"

using namespace std;



// observe and find the rule
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // create n*n matrix
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cnt = 1;
        for (int layer = 0; layer < (n+1)/2; ++layer) {
          // dir 1
          for (int i = layer; i < n-layer; ++i) {
              res[layer][i] = cnt++;
          }
          // dir 2
          for (int i = layer+1; i < n - layer; ++i) {
            res[i][n-layer-1] = cnt++;
          }
          // dir 3
          for (int i = n-layer-2; i >= layer; --i) {
            res[n-layer-1][i] = cnt++;
          }
          // dir 4
          for (int i = n-layer-2; i >layer; --i) {
            res[i][layer] = cnt++;
          }
        }
        return res;
    }
};
// @lc code=end
 
    
