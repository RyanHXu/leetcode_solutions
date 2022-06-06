/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include "bits/stdc++.h"

using namespace std;

// think this problem as soldier in a line
// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n1 = temperatures.size();
    stack<int> s;
    vector<int> res(n1, 0);

    // store index instead of elements
    for (int i = n1 - 1; i >= 0; --i) {
      while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
        s.pop();
      }

      res[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }

    return res;
  }
};
// @lc code=end
