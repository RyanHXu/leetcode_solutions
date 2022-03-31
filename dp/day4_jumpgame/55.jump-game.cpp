/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include "bits/stdc++.h"

using namespace std;

// backtrack
// top down
// button up
// greedy

// @lc code=start
// for each step, we check if index of steps + nums[index] >= lastPos, and update lastPos.
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int lastPos = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (i + nums[i] >= lastPos) {
        lastPos = i;
      }
    }
    return lastPos == 0;
  }
};

// @lc code=end

// check if we reach the last index of nums
// greedy
class Solution2 {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int lastPos = n - 1;
    // from the second to the last index
    for (int i = n - 1 - 1; i > -1; --i) {
      if ((i + nums[i]) >= lastPos) {
        lastPos = i;
      }
    }

    return lastPos == 0;
  }
};

// button up
enum Index { GOOD, BAD, UNKNOWN };

class Solution2 {
  vector<Index> dp;
  int n;

public:
  bool canJump(vector<int> &nums) {
    n = nums.size();
    dp = vector<Index>(n, UNKNOWN);
    dp[n - 1] = GOOD;
    return canJumpFromPos(0, nums);
  }

  bool canJumpFromPos(int pos, vector<int> &nums) {
    if (dp[pos] != UNKNOWN) {
      return dp[pos] == GOOD ? true : false;
    }

    int furtureJump = min(pos + nums[pos], n - 1);

    for (int nextJump = pos + 1; nextJump < furtureJump + 1; ++nextJump) {
      if (canJumpFromPos(nextJump, nums)) {
        dp[pos] = GOOD;
        return true;
      }
    }
    dp[pos] = BAD;
    return false;
  }
};

int main() {
  Index in = BAD;
  cout << in << endl;
}