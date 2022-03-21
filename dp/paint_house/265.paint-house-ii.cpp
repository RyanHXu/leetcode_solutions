/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int minCostII(vector<vector<int>> &costs) {
    int n = costs.size(); // row
    int k = costs[0].size(); // column
    for (int i = n - 2; i >= 0; --i)
    {

        for (int j = 0; j < k; ++j) {
            costs[i][j] += helper(costs[i + 1], j);
        }
    }
    int res = INT32_MAX;
    for (int i = 0; i < k; ++i) {
        res = min(res, costs[0][i]);
    }
    return res;
  }

  int helper(vector<int> &row, int index){
      int res = INT32_MAX;
      for (int i = 0; i < row.size(); ++i) {
        if(index != i){
            res = min(res, row[i]);
        }
      }
      return res;
  }
};
// @lc code=end




int main(){
    Solution s;
    vector<vector<int>> ivec{{17,9,6,2,6,18,8,12,3,5,9,11,20,8,13,16}};
    cout<<s.minCostII(ivec) << endl;
}