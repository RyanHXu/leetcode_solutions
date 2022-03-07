/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

#include "bits/stdc++.h"

using namespace std;

// TODO: second review
// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int j = 1, count = 1, n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i - 1]) {
        ++count;
      } else {
        count = 1;
      }

      if (count <= 2) {
        nums[j++] = nums[i];
      }
    }
    return j;
  }
};
// @lc code=end

class Solution2 {
public:
  void remElement(vector<int> &nums, int index) {
    for (int i = index + 1; i < nums.size(); ++i) {
      nums[i - 1] = nums[i];
    }
  }
  int removeDuplicates(vector<int> &nums) {
    int i = 1, count = 1, n = nums.size();
    while (i < n) {
      if (nums[i - 1] == nums[i]) {
        ++count;
        if (count > 2) {
          remElement(nums, i);
          --i;
          --n;
        }
      } else {
        count = 1;
      }
      ++i;
    }
    return n;
  }
};
int main() {
  vector<int> ivec{1, 1, 1, 2, 2, 3};
  Solution s;
  cout << s.removeDuplicates(ivec) << endl;
}