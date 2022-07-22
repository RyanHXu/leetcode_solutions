/*
 * @lc app=leetcode id=1152 lang=cpp
 *
 * [1152] Analyze username Website Visit Pattern
 */

#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/analyze-user-website-visit-pattern/

// https://leetcode.com/problems/analyze-user-website-visit-pattern/discuss/357252/C%2B%2B-maps-and-sets

// TODO: followup, if input timestamp is unsorted, what would you do
// @lc code=start

class Solution {
public:
  vector<string> mostVisitedPattern(vector<string> &username,
                                    vector<int> &timestamp,
                                    vector<string> &website) {
    // we require map here, because we need an increasing string
    unordered_map<string, map<int, string>> m;
    unordered_map<string, int> cnt;
    int n = username.size();
    string res;
    int m_cnt = 0;

    for (int i = 0; i < n; ++i)
      m[username[i]][timestamp[i]] = website[i];

    for (auto &val : m) {
      unordered_set<string> ts;
      for (auto it1 = val.second.begin(); it1 != val.second.end(); ++it1) {
        for (auto it2 = next(it1); it2 != val.second.end(); ++it2) {
          for (auto it3 = next(it2); it3 != val.second.end(); ++it3) {
            ts.insert(it1->second + "$" + it2->second + "#" + it3->second);
          }
        }
      }
      for (auto &val : ts) {
        ++cnt[val];
      }
    }

    for (auto &val : cnt) {
      if (m_cnt <= val.second) {
        res = res == "" || m_cnt < val.second ? val.first : min(res, val.first);
        m_cnt = val.second;
      }
    }

    auto p1 = res.find("$"), p2 = res.find("#");
    return {res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1),
            res.substr(p2 + 1)};
  }
};

// @lc code=end


int main() {
  Solution s;
  vector<string> username{"joe",   "joe",   "joe",  "james", "james",
                          "james", "james", "mary", "mary",  "mary"};
  //   vector<int> timestamp{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> timestamp{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<string> website{"home", "about", "career", "home",  "cart",
                         "maps", "home",  "home",   "about", "career"};

  // "home","about","career"
  for (const auto &val : s.mostVisitedPattern(username, timestamp, website)) {
    cout << val << endl;
  }
}
/**
["joe","joe","joe",
"james","james","james","james",
"mary","mary","mary"],

timestamp = [1,2,3,4,5,6,7,8,9,10],

website = ["home","about","career",
"home","cart","maps",
"home",
"home","about","career"]


 */