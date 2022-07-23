/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

// https://www.cs.usfca.edu/~galles/visualization/DisjointSets.html

// https://leetcode.com/discuss/general-discussion/1072418/Disjoint-Set-Union-(DSU)Union-Find-A-Complete-Guide

// https://zhuanlan.zhihu.com/p/32112569

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

class Solution {
public:
  class DisjointSets {
  public:
    vector<int> sets;
    // count is special for this question
    int count;
    DisjointSets(int size) {
      count = size;
      sets = vector<int>(size, -1);
    }
    int find(int child) {
      if (sets[child] < 0)
        return child;
        // path compression
      return sets[child] = find(sets[child]);
    }
    void unionTwo(int i, int j) {
      int root1 = find(i);
      int root2 = find(j);
      if (root1 == root2)
        return;
      count -= 1;
      int newSize = sets[root1] + sets[root2];
      // root1 is more negative (larger)
      if (sets[root1] < sets[root2]) {
        sets[root2] = root1;
        sets[root1] = newSize;
      } else {
        sets[root1] = root2;
        sets[root2] = newSize;
      }
    }
  };

  int findCircleNum(vector<vector<int>> &isConnected) {
    DisjointSets ds(isConnected.size());
    for (int i = 0, n = isConnected.size(); i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (isConnected[i][j])
          ds.unionTwo(i, j);
      }
    }
    return ds.count;
  }
};
// @lc code=end

int main() {
  vector<vector<int>> ivec{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  vector<vector<int>> ivec2{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Solution s;
  cout << s.findCircleNum(ivec) << endl;
  cout << s.findCircleNum(ivec2) << endl;

}



