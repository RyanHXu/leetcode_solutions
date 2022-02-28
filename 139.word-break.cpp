/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
    unordered_map<string, bool> mem;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    }
};
// @lc code=end

