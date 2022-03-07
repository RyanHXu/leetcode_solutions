/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// divide and conquer
class Solution {
public:
  int countInRange(vector<int> &nums, int num, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
      if (nums[i] == num)
        ++count;
    }
    return count;
  }
  int majorityElementHelper(vector<int> &nums, int l, int r) {
    if (l == r) {
      return nums[l];
    }
    int m = l + (r - l) / 2;
    int left = majorityElementHelper(nums, l, m);
    int right = majorityElementHelper(nums, m + 1, r);
    if (left == right) {
      return left;
    }

    int lcount = countInRange(nums, left, l, r);
    int rcount = countInRange(nums, right, l, r);

    return lcount > rcount ? left : right;
  }
  int majorityElement(vector<int> &nums) {
    return majorityElementHelper(nums, 0, nums.size() - 1);
  }
};

// @lc code=end

// math
// 1 2 3 4 4 4 4
// n/2 => index of 3 => 4
// 1 2 3 4 4 4
// n/2 => 3 index of 3 => 4
// so n/2 both works for even length and odd length vector
class Solution2 {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return nums[n / 2];
  }
};

// map
class Solution3 {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    for (const auto val : nums) {
      ++m[val];
    }
    for (const auto val : m) {
      if (val.second > n / 2) {
        return val.first;
      }
    }
    return 0;
  }
};

// TODO:
// Boyer-Moore Voting Algorithm
class Solution4 {
public:
  int majorityElement(vector<int> &nums) {
    int count = 0;
    int candidate = INT32_MIN;
    for (const auto val : nums) {
      if (count == 0) {
        candidate = val;
      }
      count += (val == candidate) ? 1 : -1;
    }
    return candidate;
  }
};

int main() {
  vector<int> ivec{2, 1, 2, 1, 2, 1, 2};
  Solution s;
  cout << s.majorityElement(ivec) << endl;
}