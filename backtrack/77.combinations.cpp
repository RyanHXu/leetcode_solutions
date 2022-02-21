/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
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
class Solution {
  vector<vector<int>> res;

public:
  vector<vector<int>> combine(int n, int k) {
    backtrack(1, n, k, {});
    return res;
  }

  void backtrack(int first, int n, int k, vector<int> comb) {
    if (comb.size() == k) {
      res.push_back(comb);
    }

    for (size_t i = first; i < n + 1; ++i) {
      comb.push_back(i);
      backtrack(i + 1, n, k, comb);
      comb.pop_back();
    }
  }
};
// @lc code=end


int main(){
  cout << "hello world" << endl;
}