/*
 * @lc app=leetcode id=267 lang=cpp
 *
 * [267] Palindrome Permutation II
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
  unordered_map<char, int> m;
  vector<string> res;

public:
  vector<string> generatePalindromes(string s) {
    if (!checkPalindromePermutation(s)) {
      return {};
    }

    string str;
    char c = '\0';

    for (const auto val : m) {
      if (val.second > 1) {
        str += genString(val.first, val.second / 2);
        if (val.second % 2 == 1) {
          c = val.first;
        }
      } else {
        c = val.first;
      }
    }

    backtrack(str, 0);
    string t;
    for (int i = 0; i < res.size(); ++i) {
      if (c != '\0') {
        t = res[i];
        reverse(t.begin(), t.end());
        res[i] += c + t;
      } else {
        t = res[i];
        reverse(t.begin(), t.end());
        res[i] += t;
      }
    }

    return res;
  }
  void backtrack(string &permulation, int start) {
    if (start == permulation.size()) {
      res.push_back(permulation);
    }
    for (int i = start; i < permulation.size(); ++i) {
      if (i != start || permulation[i] != permulation[start]) {
        swap(permulation[i], permulation[start]);
        backtrack(permulation, start + 1);
        swap(permulation[i], permulation[start]);
      }
    }
  }

  string genString(char c, int num) {
    string str;
    for (int i = 0; i < num; ++i) {
      str += c;
    }
    return str;
  }

  bool checkPalindromePermutation(string s) {
    for (const auto val : s) {
      ++m[val];
    }
    int count = 0;
    for (const auto val : m) {
      count += val.second % 2;
    }

    return count <= 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  for (const auto val : s.generatePalindromes("abba")) {
    cout << val << endl;
  }
}