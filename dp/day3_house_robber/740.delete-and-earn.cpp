/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// ButtonUpOpimizeSpace
class Solution {

public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> points;

    int maxElement = 0;
    int n = nums.size();
    for (const auto &val : nums)
    {
        points[val] += val;
        maxElement = max(maxElement, val);
    }

    int oneBack = points.count(1)?points[1]:0;
    int twoBack = 0;

    // start from 1
    for (int i = 2; i < maxElement+1; ++i) {
      int val = points.count(i) ? points[i] : 0;
      int temp = oneBack;
      oneBack = max(oneBack, twoBack +val);
      twoBack = temp;
    }
    return oneBack;
  }
};
// @lc code=end


class SolutionButtonUp {

public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> points;

    int maxElement = 0;
    int n = nums.size();
    for (const auto &val : nums)
    {
        points[val] += val;
        maxElement = max(maxElement, val);
    }

    vector<int> dp(maxElement + 1, 0);
    dp[1] = points[1];


    // start from 1
    for (int i = 2; i < maxElement+1; ++i) {
        int curr = points.count(i) ? points[i] : 0;
        dp[i] = max(dp[i - 1], dp[i - 2] + curr);
    }
    return dp[maxElement];
  }
};

class SolutionTopDown {

  unordered_map<int, int> points;
  unordered_map<int, int> dp;

public:
  int deleteAndEarn(vector<int> &nums) {
    int maxElement = 0;
    for (const auto &val : nums) {
      points[val] += val;
      maxElement = max(maxElement, val);
    }
    return deleteAndEarnTopDown(maxElement);
  }

  int deleteAndEarnTopDown(int num) {
    if (num <= 0) {
      return 0;
    }
    if (dp.find(num) == dp.end()) {
      int curr = points.count(num) ? points[num] : 0;
      dp[num] = max(deleteAndEarnTopDown(num - 2) + curr,
                    deleteAndEarnTopDown(num - 1));
    }
    return dp[num];
  }
};
int main() {
  // c++ map default value
  //   unordered_map<int, int> m;
  //   for (int i = 0; i < 10; ++i) {
  //     m[i] += i + 10;
  //   }
  //   for (int i = 0; i < 10; ++i) {
  //     cout << m[i] << endl;
  //   }

  //   vector<int> ivec{10, 20, 20, 20, 30, 30, 20, 20, 10};
  //   sort(ivec.begin(), ivec.end());
  //   auto unique_it = unique(ivec.begin(), ivec.end());
  //   for (auto it = ivec.begin(); it != ivec.end(); ++it) {
  //     cout << *it << endl;
  //   }

  //   cout << endl;
  //   for (auto it = ivec.begin(); it != unique_it; ++it) {
  //     cout << *it << endl;
  //   }

  //   cout << endl;
  //   cout << m[100] << endl;
  //   cout << m[10000] << endl;
  //   cout << m[100000] << endl;
  //   cout << m.size() << endl;
  Solution s;
  vector<int> nums{2, 2, 3, 3, 3, 4};
  cout << s.deleteAndEarn(nums) << endl;
}
