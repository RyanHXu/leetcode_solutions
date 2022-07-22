/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include "bits/stdc++.h"

using namespace std;

// https://www.youtube.com/watch?v=KB9IcSCDQ9k
// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    // Make sure n1 <= n2
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    const int k = (n1 + n2 + 1) / 2;
    // 9, 5
    // 10, 5

    int l = 0;
    int r = n1;

    while (l < r) {
      const int m1 = l + (r - l) / 2;
      const int m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1])
        l = m1 + 1;
      else
        r = m1;
    }

    const int m1 = l;
    const int m2 = k - l;

    const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                       m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((n1 + n2) % 2 == 1) return c1;

    const int c2 =
        min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);

    return (c1 + c2) * 0.5;
  }
};

// @lc code=end

// TODO: two pointer, pop_front
class Solution2 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int k = n / 2 - 1;

    deque<int, vector<int>> q1(nums1);
    deque<int, vector<int>> q2(nums2);

    int res = 0;
    while (k-- > 0 && !q1.empty() && !q2.empty()) {
      if (q1.front() < q2.front()) {
        res = q1.front();
        q1.pop_front();
      } else {
        res = q2.front();
        q2.pop_front();
      }
    }
  }
};