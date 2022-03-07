/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    if (s.length() < k + 1) {
      return n;
    }

    int left = 0, right = 0;
    int res = 0;
    unordered_map<char, int> m;
    while (right < n)
    {
        m[s[right]] = right;
        ++right;
        
        if(m.size()==k+1){
            int del_idx = INT32_MAX;
            for (const auto& [key, freq] : m) {
                del_idx = min(del_idx, freq);
            }
            m.erase(s[del_idx]);
            left = del_idx + 1;
        }
        res = max(res,right - left);
    }
    return res;
  }
};
// @lc code=end
