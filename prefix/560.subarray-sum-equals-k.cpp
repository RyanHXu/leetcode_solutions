/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// time complexity: O(N*N)
// space complexity: O(1)
// hashmap + prefix
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, count = 0;
    m[sum] = 1;
    for (auto& val : nums) {
      sum += val;
      // NOTE: sum % k doesn't work here. For example, [10,10,10] and 5
      int target = sum - k;
      if (m[target]) count += m[target];

      ++m[sum];
    }

    return count;
  }
};

// @lc code=end

// brute force
// time complexity: O(N^3)
// space complexity: O(1)
class SolutionNative {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    // i => start, j => end
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j <= nums.size(); ++j) {
        int sum = 0;
        for (int h = i; h < j; ++h) {
          sum += nums[i];
        }
        if (sum == k) ++count;
      }
    }
    return count;
  }
};

// time complexity: O(N*N)
// space complexity: O(N)
// Time Limit Exceeded
class SolutionCumulativeSum {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    // i=>start, j=>end
    vector<int> sum(nums.size() + 1, 0);
    // using accmulative sum
    for (int i = 1; i < nums.size() + 1; ++i) sum[i] = sum[i - 1] + nums[i - 1];

    for (int start = 0; start < nums.size(); ++start) {
      for (int end = start + 1; end < nums.size() + 1; ++end) {
        if (sum[end] - sum[start] == k) ++count;
      }
    }

    return count;
  }
};

// time complexity: O(N*N)
// space complexity: O(1)
// Optimized Space
// Time Limit Exceeded
class SolutionCumulativeSum2 {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum;

    for (int start = 0; start < nums.size(); ++start) {
      sum = 0;
      for (int end = start; end < nums.size(); ++end) {
        sum += nums[end];
        if (sum == k) ++count;
      }
    }

    return count;
  }
};

int main() {
  Solution s;
  // vector<int> ivec{3,4,7,2,-3,1,4,2};
  // cout<<s.subarraySum(ivec,7) << endl;
    vector<int> ivec{3,4,1,6,-3};
  cout<<s.subarraySum(ivec,7) << endl;
}