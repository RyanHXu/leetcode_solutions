/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */
#include "bits/stdc++.h"

using namespace std;
// sliding windows
// prefix
// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window

// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window

// TODO:
/**
Number of Substrings Containing All Three Characters
Count Number of Nice Subarrays
Replace the Substring for Balanced String
Max Consecutive Ones III
Binary Subarrays With Sum
Subarrays with K Different Integers
Fruit Into Baskets
Shortest Subarray with Sum at Least K
Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
  }
  int atMostK(vector<int> &nums, int k) {
    int left = 0, res = 0;
    unordered_map<int, int> m;
    for (int right = 0; right < nums.size(); ++right) {
      if (!m[nums[right]]++) {
          --k;
      }
      while (k < 0) {
        if (!--m[nums[left]])
          ++k;
        ++left;
      }
      res += right - left + 1;
    }
    return res;
  }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> ivec{1, 2, 1, 2, 3};
    cout << s.subarraysWithKDistinct(ivec, 2) << endl;
}
