/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int once = 0, twice = 0;
    for (const auto &val : nums) {
      once = ~twice & (val ^ once);
      twice = ~once & (val ^ twice);
    }

    return once;
  }
};
// @lc code=end

// set<long>
class Solution2 {
public:
  int singleNumber(vector<int> &nums) {
    // key: frequence
    unordered_set<long> s;
    for (const auto &val : nums) {
      s.insert(val);
    }
    return (accumulate(s.begin(), s.end(), 0ll) * 3 -
            accumulate(nums.begin(), nums.end(), 0ll)) /
           2;
  }
};

// map
class Solution3 {
public:
  int singleNumber(vector<int> &nums) {
    // key: frequence
    unordered_map<int, int> m;
    for (const auto &val : nums) {
      ++m[val];

      if (m[val] == 3)
        m.erase(val);
    }
    return m.begin()->first;
  }
};

int main() {
  vector<int> ivec{
      43,          16,         45,          89,          45,
      -2147483648, 45,         2147483646,  -2147483647, -2147483648,
      43,          2147483647, -2147483646, -2147483648, 89,
      -2147483646, 89,         -2147483646, -2147483647, 2147483646,
      -2147483647, 16,         16,          2147483646,  43};
  Solution s;
  cout << s.singleNumber(ivec) << endl;
}