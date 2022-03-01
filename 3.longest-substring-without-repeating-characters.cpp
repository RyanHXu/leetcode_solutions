/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        int i = 0;
        int res = 0;

        for (int j = 0; j < n; ++j) {
          if(m.find(s[j])!=m.end()){
              i = max(i, m[s[j]]);
          }
          res = max(res, j - i + 1);
          m[s[j]] = j + 1;
        }
        return res;
    }
};
// @lc code=end

