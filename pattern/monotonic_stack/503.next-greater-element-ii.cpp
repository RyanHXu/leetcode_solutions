/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

#include "bits/stdc++.h"

using namespace std;
// https://github.com/labuladong/fucking-algorithm/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E5%8D%95%E8%B0%83%E6%A0%88.md

// @lc code=start
// 1 2 1
// 1 2 1 1 2 1
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = n * 2 - 1; i >= 0; --i) {
      while (!s.empty() && s.top() <= nums[i % n]) {
        s.pop();
      }

      res[i % n] = s.empty() ? -1 : s.top();

      s.push(nums[i % n]);
    }

    return res;
  }
};
// @lc code=end
