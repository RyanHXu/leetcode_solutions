/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if(n==1){
        return nums[0];
    }

    return max(robButtonUp(nums, 0, n - 2), robButtonUp(nums, 1, n - 1));
  }

  
  int robButtonUp(vector<int> &nums, int l, int r){
      int robNext = 0, robNextPlugOne = 0,curr=0;
      for (int i = r; i >=l; --i) {
          curr = max(nums[i] + robNextPlugOne, robNext);
          robNextPlugOne = robNext;
          robNext = curr;
      }

      return robNext;
  }
};

// @lc code=end


// https://leetcode.com/problems/house-robber-ii/discuss/1682761/C%2B%2B-or-4-APPROACHES-or-DP-or-MEMO-or-O(1)-SPACE-AND-O(N)-TIME
// topdown with memo
// create 2 row to record
class SolutionTopDown {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    vector<vector<int>> dp(2, vector<int>(n, -1));
    

    // skip the last element or skip the first element
    return max(robTopDown(dp[0], nums, 0, n - 2),
               robTopDown(dp[1], nums, 1, n - 1));
  }

  int robTopDown(vector<int> &dp, vector<int> &nums, int l, int r) {
    if (r < l) {
      return 0;
    }

    if (dp[r] == -1) {
      dp[r] = max(robTopDown(dp, nums, l, r - 1),
                  nums[r] + robTopDown(dp, nums, l, r - 2));
    }

    return dp[r];
  }
};

int main() {
  Solution s;

  vector<int> ivec{2, 3, 2};
  cout << s.rob(ivec) << endl;

  vector<int> ivec2{1, 2, 3, 1};
  cout << s.rob(ivec2) << endl;

  vector<int> ivec3{1, 2, 3};
  cout << s.rob(ivec3) << endl;
}