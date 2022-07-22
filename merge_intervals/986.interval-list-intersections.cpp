/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/interval-list-intersections/discuss/646988/C%2B%2B-or-Easy-or-6-lines-or-Two-pointer-or-100
// simplified code

// @lc code=start

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
    vector<vector<int>>& B) {

    vector<vector<int>> v;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
      int l = max(A[i][0], B[j][0]);
      int u = min(A[i][1], B[j][1]);
      // check if interset
      if (l <= u) v.push_back({l, u});
      if (A[i][1] < B[j][1])
        ++i;
      else
        ++j;
    }
    return v;
  }
};
// @lc code=end





class Solution2 {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
    vector<vector<int>>& secondList) {
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (i < firstList.size() && j < secondList.size()) {
      // check if the interval arr[i] intersects with arr[j]
      // check if one of the interval's start time lies within the other
      // interval
      if ((firstList[i][0] >= secondList[j][0] &&
           firstList[i][0] <= secondList[j][1]) ||
          (secondList[j][0] >= firstList[i][0] &&
           secondList[j][0] <= firstList[i][1])) {
        // store the intersection part
        res.push_back({max(firstList[i][0], secondList[j][0]),
                       min(firstList[i][1], secondList[j][1])});
      }

      // move next from the interval which is finishing first
      if (firstList[i][1] < secondList[j][1]) {
        ++i;
      } else {
        ++j;
      }
    }

    return res;
  }
};