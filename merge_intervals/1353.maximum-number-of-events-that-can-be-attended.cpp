/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

#include "bits/stdc++.h"

using namespace std;

// https://www.youtube.com/watch?v=NjF9JGDGxg8

// @lc code=start

class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    sort(begin(events), end(events),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int min_d = INT32_MAX;
    int max_d = INT32_MIN;
    for (const auto& val : events) {
      min_d = min(min_d, val[0]);
      max_d = max(max_d, val[1]);
    }

    vector<int> days(max_d - min_d + 1);
    iota(begin(days), end(days), min_d);
    set<int> s(begin(days), end(days));

    int res = 0;
    for (const auto& val : events) {
      auto it = s.lower_bound(val[0]);
      if (it == end(s) || *it > val[1]) continue;
      s.erase(it);
      ++res;
    }
    return res;
  }
};

// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> temp{2, 4, 6, 8, 10};
  // 4,6,6,6
  
  // lower_bound:
  // Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.

  // upper_bound: 
  // Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
  cout << *lower_bound(temp.begin(), temp.end(), 4) << '\n';
  cout << *lower_bound(temp.begin(), temp.end(), 5) << '\n';
  cout << *upper_bound(temp.begin(), temp.end(), 4) << '\n';
  cout << *upper_bound(temp.begin(), temp.end(), 5) << '\n';
  return 0;
}
