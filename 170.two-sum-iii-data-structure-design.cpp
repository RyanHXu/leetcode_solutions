/*
 * @lc app=leetcode id=170 lang=cpp
 *
 * [170] Two Sum III - Data structure design
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// sort + fast&slow pointers
class TwoSum {
private:
  vector<int> ivec;

public:
  TwoSum() {}
  void add(int number) { ivec.push_back(number); }

  bool find(int value) {
    if (value > 200000 || value < -200000) {
      return false;
    }

    int n = ivec.size();
    int l = 0, r = n - 1;
    sort(ivec.begin(), ivec.end());
    int sum = 0;
    while (l < r) {
      sum = ivec[l] + ivec[r];
      if (sum == value) {
        return true;
      } else if (sum < value) {
        ++l;
      } else {
        --r;
      }
    }
    return false;
  }
};
// @lc code=end

// map
// https://leetcode.com/problems/two-sum-iii-data-structure-design/discuss/892047/c%2B%2B-unordered_map-and-200K-filter-(72ms)
class TwoSum2 {
private:
  unordered_map<int, int> m;

public:
  TwoSum2() {}
  void add(int number) { ++m[number]; }

  bool find(int value) {
    if (value > 200000 || value < -200000) {
      return false;
    }
    for (const auto &[num, count] : m) {
      auto it = m.find(value - num);
      if (it == m.end()) {
        continue;
      }
      if (it->first != num || count > 1) {
        return true;
      }
    }
    return false;
  }
};