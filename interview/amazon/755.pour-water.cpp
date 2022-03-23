/*
 * @lc app=leetcode id=755 lang=cpp
 *
 * [755] Pour Water
 */
#include "bits/stdc++.h"

using namespace std;

// https://www.youtube.com/watch?v=sgDdhNTByLQ

// @lc code=start
class Solution {
public:
  vector<int> pourWater(vector<int> &heights, int volume, int k) {
    while (volume) {
      drop(heights, k);
      --volume;
    }
    return heights;
  }

  // void drop(vector<int> &heights, int k) {
  //   int best = k;
  //   // move left first, then move right
  //   for (int d = -1; d <= 1; d += 2) {
  //     int i = k + d;
  //     while (i >= 0 && i < heights.size() && heights[i] <= heights[i - d])
  //     {
  //       if (heights[i] < heights[best])
  //         best = i;
  //       i += d;
  //     }
  //     if (best != k)
  //       break;
  //   }
  //   ++heights[best];
  // }

  void drop(vector<int> &heights, int k) {
    int best = k;
    // perform two directions - move left and move right
    for (int d = -1; d <= 1; d += 2) {
      int i = k + d;
      while (i >= 0 && i < heights.size() && heights[i] <= heights[i - d]) {
        // find the most left slot
        if (heights[i] < heights[best])
          best = i;
        i += d;
      }
      // check if we found it
      // after two rounds, k still equal to best, which means we got final result
      if (k != best)
        break;
    }
    ++heights[best];
  }
};
// @lc code=end

int main() {

  int a = 10;
  while (a--) {
    cout << a << endl;
  }
}