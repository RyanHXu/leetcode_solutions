/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// two pointers
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    int sum = 0;
    while (l < r) {
      sum = numbers[l] + numbers[r];
      if (sum == target) {
        return {l + 1, r + 1};
      } else if (sum < target) {
        ++l;
      } else {
        --r;
      }
    }
    return {-1, -1};
  }
};
// @lc code=end

// map
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < numbers.size(); ++i) {
      if (m.find(numbers[i]) == m.end()) {
        // store the index of (target - num)
        m[target - numbers[i]] = i;
      } else {
        return {m[numbers[i]] + 1, i + 1};
      }
    }
    return {-1, -1};
  }
};