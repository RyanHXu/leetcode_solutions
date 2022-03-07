/*
 * @lc app=leetcode id=157 lang=cpp
 *
 * [157] Read N Characters Given Read4
 */

#include "bits/stdc++.h"

using namespace std;
// https://leetcode.com/problems/read-n-characters-given-read4/solution/

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  // return len(buff)%4==0? return len(buff)/4: len(buff)/4+1
  int read(char *buf, int n) {
    char buf4[4];
    int index = 0;
    while (true) {
      int count = read4(buf4);
      count = min(count, n - index);
      for (int i = 0; i < count; ++i) {
        buf[index++] = buf4[i];
      }
      if (index == n || count < 4) {
        return index;
      }
    }
  }
};
// @lc code=end
