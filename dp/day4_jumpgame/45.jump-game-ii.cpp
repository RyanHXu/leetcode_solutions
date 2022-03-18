/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include "bits/stdc++.h"

using namespace std;


// https://leetcode.com/problems/jump-game-ii/discuss/1192401/Easy-Solutions-w-Explanation-or-Optimizations-from-Brute-Force-to-DP-to-Greedy-BFS

// @lc code=start

// button up
class Solution {
public:
  int jump(vector<int> &nums) {
    int jumps = 0, currJumpEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
     
    }
  }
};
// @lc code=end


// greedy BFS
class Solution {
public:
  int jump(vector<int> &nums) {
    int jumps = 0, currJumpEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = max(farthest, i + nums[i]);

      if (i == currJumpEnd) {
        ++jumps;
        currJumpEnd = farthest;
      }
    }
    return jumps;
  }
};

int main() {
  Solution s;
  vector<int> ivec{2, 3, 1, 1, 4};
  cout << s.jump(ivec) << endl;
}
