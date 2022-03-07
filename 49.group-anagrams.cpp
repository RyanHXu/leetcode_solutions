/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// map & count elements number
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    if (strs.size() == 0) {
      return {{}};
    }
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    vector<int> count(26, 0);
    for (const auto val : strs)
    {
        fill(count.begin(), count.end(), 0);
        for (const auto c : val) {
            ++count[c - 'a'];
        }
        string key;
        for (int i = 0; i < 26; ++i) {
            key += '#';
            key += count[i];
        }
        m[key].push_back(val);
    }

    for (const auto val : m) {
      res.push_back(val.second);
    }
    return res;
  }
};
// @lc code=end


class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    if (strs.size() == 0) {
      return {{}};
    }
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    for (const auto val : strs) {
      string key = val;
      sort(key.begin(), key.end());
      m[key].push_back(val);
    }

    for (const auto val : m) {
      res.push_back(val.second);
    }
    return res;
  }
};
int main() {
  string str("hello world");
  // convert string to vector<char>
  vector<char> cvec(str.begin(), str.end());
  vector<char> cvec2;
  copy(str.begin(), str.end(), back_inserter(cvec2));
  for (const auto val : cvec) {
    cout << val << ' ';
  }
  cout << endl;
  for (const auto val : cvec2) {
    cout << val << ' ';
  }
  cout << endl;

  sort(str.begin(), str.end());
  cout << str << endl;

  Solution s;
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  for (const auto it : s.groupAnagrams(strs)) {
      for (const auto val : it) {
        cout << val << ' ';
      }
      cout << endl;
    }
   cout << endl;

    
  
}
