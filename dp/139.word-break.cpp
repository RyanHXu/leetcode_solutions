/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include "bits/stdc++.h"

using namespace std;

// TODO: review
// @lc code=start
class Solution {
    unordered_map<string, bool> mem;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s,dict);
    }

    bool wordBreak(const string& s, const unordered_set<string>& dict){
        if(mem.count(s))
            return mem[s];
        if(dict.count(s))
            return mem[s] = true;
        for (int i = 1; i < s.length(); ++i) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            if(dict.count(right) && wordBreak(left,dict))
                return mem[s] = true;
        }
        return mem[s] = false;
    }
};

// @lc code=end

int main(){
    string str("leetcode");
    vector<string> svec{"leet", "code"};
    Solution s;
    s.wordBreak(str, svec);
}
