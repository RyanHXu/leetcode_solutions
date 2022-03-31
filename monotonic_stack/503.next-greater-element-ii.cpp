/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && nums[i] >= s.top()) {
        s.pop();
      }

      res[i] = s.empty() ? -1 : s.top();
      s.push(nums[i]);
    }
    return res;
  }
};
// @lc code=end
