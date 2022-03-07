/*
 * @lc app=leetcode id=734 lang=cpp
 *
 * [734] Sentence Similarity
 */
#include "bits/stdc++.h"

using namespace std;
// https://leetcode.com/problems/sentence-similarity/discuss/1756931/C++-faster-than-100-using-hashset

// @lc code=start
class Solution {
public:
  bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2,
                           vector<vector<string>> &similarPairs) {
    if (sentence1.size() != sentence2.size()) {
      return false;
    }

    // beautiful solution
    unordered_set<string> m;

    for (const auto val : similarPairs) {
      m.insert(val[0] + ',' + val[1]);
      m.insert(val[1] + ',' + val[0]);
    }
    for (int i = 0; i < sentence1.size(); ++i) {
      if (sentence1[i] != sentence2[i] &&
          m.count(sentence1[i] + ',' + sentence2[i]) == 0)
        return false;
    }
    return true;
  }
};
// @lc code=end
