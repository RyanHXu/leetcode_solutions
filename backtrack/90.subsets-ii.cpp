/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include "bits/stdc++.h"

using namespace std;

// https://www.educative.io/courses/grokking-the-coding-interview/7npk3V3JQNr

// @lc code=start

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res{{}};
    // sort all numbers and make sure all of them are next to each other
    sort(nums.begin(), nums.end());
    int start, end;
    int n = nums.size();
    vector<int> temp;
    for (int i = 0; i < n; ++i) {
      start = 0;

      if (i > 0 && nums[i - 1] == nums[i]) {
        start = end + 1;
      }
      end = res.size() - 1;

      for (int j = start; j <= end; ++j) {
        temp = res[j];
        temp.push_back(nums[i]);
        res.push_back(temp);
      }
    }
    return res;
  }
};

// @lc code=end

// TODO: backtrack
class Solution2 {
  vector<vector<int>> res;
  vector<int> subset;
  int k;

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    res = {};
    subset = {};
    for (k = 0; k < nums.size() + 1; ++k) {
      backtrack(nums, subset, 0);
    }
    return res;
  }
  void backtrack(vector<int> &nums, vector<int> &subset, int start) {
    if (subset.size() == k) {
      res.push_back(subset);
    }

    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }
      subset.push_back(nums[i]);
      backtrack(nums, subset, i + 1);
      subset.pop_back();
    }
  }
};

int main() {
  Solution2 s;
  vector<int> ivec;
  ivec = {1, 2, 2};
  for (const auto &it : s.subsetsWithDup(ivec)) {
    for (const auto &val : it) {
      cout << val << ' ';
    }
    cout << endl;
  }
  cout << endl;

  ivec = {1, 2, 3};
  for (const auto &it : s.subsetsWithDup(ivec)) {
    for (const auto &val : it) {
      cout << val << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

/*
1
2
1 2
2 2
1 2 2


1
2
1 2
3
1 3
2 3
1 2 3


*/