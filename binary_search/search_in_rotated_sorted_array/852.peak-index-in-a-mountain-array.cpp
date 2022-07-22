/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

#include "bits/stdc++.h"

using namespace std;

// NOTE: find max element in an array
// https://zxi.mytechroad.com/blog/algorithms/binary-search/%e8%8a%b1%e8%8a%b1%e9%85%b1-leetcode-162-find-peak-element/

// @lc code=start
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (arr[m] > arr[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
// @lc code=end
