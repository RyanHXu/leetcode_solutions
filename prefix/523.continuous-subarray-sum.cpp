/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */
#include "bits/stdc++.h"

using namespace std;

// NOTE:
// brilliant solution
// https://leetcode.com/problems/continuous-subarray-sum/discuss/1388564/oror-C%2B%2B-oror-Crystal-Clear-Solution-oror-PREFIX-SUM-oror-Explanation-oror-O(N)-time-using-Map

/*
For a iteration from o to n, we are storing sum(o, i) mod k in the map. Before
storing the value, we check whether the same value which is sum(o,i) mod k
already stored in map or not. If the same value was saved in the array, we will
return true and the program will end.
*/

// @lc code=start

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;

    int sum = 0, presum = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
      sum = (sum + nums[i]) % k;
      if (m[sum]) return true;
      ++m[presum];
      presum = sum;
    }
    return false;
  }
};
// @lc code=end
