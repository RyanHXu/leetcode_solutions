/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> m;
    for (const auto &val : nums) {
      ++m[val];
    }
    sort(nums.begin(), nums.end(),
         [&](const auto &a, const auto &b) { 
             if(m[a]==m[b]){
                 return a > b;
             }
             return m[a]<m[b];
             
             });

    return nums;

  }
};
// @lc code=end
