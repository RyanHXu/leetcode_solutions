/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// the idea is never reduce the size of windows
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int left = 0, right;
    int n = nums.size();
    for (right = 0; right < n; ++right) {
      if (nums[right] == 0)
        --k;
      if (k < 0) {
        if(nums[left]==0){
          ++k;
        }
        ++left;
      }
    }

    return right - left;
  }
};
// @lc code=end
int main(){
    vector<int> ivec{0, 1, 1, 1, 0};
    Solution s;
    cout << s.longestOnes(ivec, 0) << endl;
}