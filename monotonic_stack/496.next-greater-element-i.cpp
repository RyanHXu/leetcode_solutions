/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

#include "bits/stdc++.h"

using namespace std;

// Next Greater Element
// time complexity: O(N+N+M) => O(N)
// nums2 pushed and poped once, nums1 is also scanned only once
// space complexity: O(N) 


// @lc code=start

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int len_nums1 = nums1.size();
    int len_nums2 = nums2.size();
    vector<int> res(len_nums1,-1);
    stack<int> s;
    map<int, int> m;

    for (int i = 0; i < len_nums2; ++i) {
      while (!s.empty() && nums2[i] > s.top()) {
        m[s.top()] = nums2[i];
        s.pop();
      }

      s.push(nums2[i]);
    }

    for (int i = 0; i < len_nums1; ++i) {
      if(m.count(nums1[i])){
        res[i] = m[nums1[i]];
      }
    }

    return res;
  }
};
// @lc code=end

// better brute force
// Instead of searching for the occurence of nums1[i]nums1[i] linearly in the
// nums2nums2 array, we can make use of a hashmap hashhash to store the elements
// of nums2nums2 in the form of (element, index)(element,index). By doing this,
// we can find nums1[i]nums1[i]'s index in nums2nums2 array directly and then
// continue to search for the next larger element in a linear fashion.
class Solution2 {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // nums2[i], index of nums2[i]
    map<int, int> m;
    for (int i = 0; i < nums2.size(); ++i) {
      m[nums2[i]] = i;
    }
    int len_nums1 = nums1.size();
    int len_nums2 = nums2.size();

    vector<int> res(len_nums1, -1);
    for (int i = 0; i < len_nums1; ++i) {
      for (int j = (m[nums1[i]] + 1); j < len_nums2; ++j) {
        if (nums1[i] < nums2[j]) {
          res[i] = nums2[j];
          break;
        }
      }
    }

    return res;
  }
};

// ✅ naive solution
// time complexity: O(N*N)
class Solution3 {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); ++i) {
      bool flag = false;
      for (int j = 0; j < nums2.size(); ++j) {
        if (nums2[j] == nums1[i]) {
          flag = true;
          continue;
        }
        if (flag && nums2[j] > nums1[i]) {
          res[i] = nums2[j];
          flag = false;
          break;
        }
      }
    }
    return res;
  }
};