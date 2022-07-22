/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  // O(nlogn*log(max – min))
  // find the index of smallest num + k among N-sorted lists
  // NOTE: https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-378-kth-smallest-element-in-a-sorted-matrix/
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r) {
      long m = l + (r - l) / 2;
      int total = 0;
      int s = n;
      for (const auto &row : matrix)
        total += (s = distance(begin(row),
                               upper_bound(begin(row), begin(row) + s, m)));
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
// @lc code=end

// priority_queue
class Solution2 {
  typedef pair<int, pair<int, int>> myPair;

 public:
  // pair<value,index_in_row>
  struct valueCompare {
    bool operator()(const myPair &x, const myPair &y) {
      return x.first > y.first;
    }
  };
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<myPair, vector<myPair>, valueCompare> minHeap;

    int n = matrix.size();
    int res;

    for (int i = 0; i < n; ++i) {
      minHeap.push({res = matrix[i][0], {i, 0}});
    }

    while (!minHeap.empty()) {
      auto temp = minHeap.top();
      res = temp.first;
      minHeap.pop();
      --k;
      if (k == 0) {
        break;
      }
      if (temp.second.second + 1 < n) {
        int i = temp.second.first;
        // next element
        int j = temp.second.second + 1;
        minHeap.push({matrix[i][j], {i, j}});
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> ivec{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  Solution s;
  cout << s.kthSmallest(ivec, 8) << endl;
  return 0;
}
