/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
  int findComplement(int num) {
    int todo = num, bit = 1;
    // while todo >0
    while (todo) {
      num = num ^ bit;
      bit <<= 1;
      todo >>= 1;
    }
    return num;
  }
};
// @lc code=end
