/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/top-k-frequent-words/discuss/431008/Summary-of-all-the-methods-you-can-imagine-of-this-problem

// @lc code=start

typedef pair<string, int> myPair;
class Solution {
public:
  struct valueCompare {
    bool operator()(const myPair &x, const myPair &y) {
      if (x.second == y.second) {
        //   greater for ascending order
        return x.first > y.first;
      }

        //   less for descending order

      return x.second < y.second;
    }
  };

  vector<string> topKFrequent(vector<string> &words, int k) {
    priority_queue<myPair, vector<myPair>, valueCompare> pq;
    unordered_map<string, int> m;
    for (const auto val : words) {
      ++m[val];
    }
    for (const auto val : m) {
      pq.push({val.first, val.second});
    }

    vector<string> res;

    while (!pq.empty() && k > 0) {
      --k;
      res.push_back(pq.top().first);
      pq.pop();
    }

    return res;
  }
};
// @lc code=end
