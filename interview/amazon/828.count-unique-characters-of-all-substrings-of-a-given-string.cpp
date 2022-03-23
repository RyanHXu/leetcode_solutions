/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/128952/C%2B%2BJavaPython-One-pass-O(N)/

// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/224001/C%2B%2B-Solution-8ms-by-%22Contribution%22

// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/129021/O(N)-Java-Solution-DP-Clear-and-easy-to-Understand

// TODO: check it out
// https://www.youtube.com/watch?v=v0iZs3-_1c4

// @lc code=start

class Solution {
public:
  int uniqueLetterString(string s) {
    const int kDivisor = 1000000007;
    int n = s.length();
    vector<int> L(n, -1), R(n, -1);
    vector<int> alpha(26, -1);

    for (int i = 0; i < n; ++i) {
      if (alpha[s[i] - 'A'] != -1)
        L[i] = alpha[s[i] - 'A'];
      alpha[s[i] - 'A'] = i;
    }

    fill(alpha.begin(), alpha.end(), -1);

    for (int i = n - 1; i >= 0; --i) {
      if (alpha[s[i] - 'A'] != -1)
        R[i] = alpha[s[i] - 'A'];
      alpha[s[i] - 'A'] = i;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      int leftBound = L[i] == -1 ? 0 : L[i] + 1;
      int rightBound = R[i] == -1 ? n - 1 : R[i] - 1;

      res += (i - leftBound + 1) * (rightBound - i + 1);
    }

    return res;
  }
};

// @lc code=end

class Solution2 {

public:
  int uniqueLetterString(string s) {
    const int kDivisor = 1000000007;
    int n = s.length();
    vector<int> L(n, -1), R(n, -1);
    vector<int> lastL(26, -1), lastR(26, n);
    for (int i = 0; i < n; ++i) {
      L[i] = i - lastL[s[i] - 'A'];
      lastL[s[i] - 'A'] = i;
    }

    for (int i = n - 1; i >= 0; --i) {
      R[i] = lastR[s[i] - 'A'] - i;
      lastR[s[i] - 'A'] = i;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = (res + (L[i] * R[i]) % kDivisor) % kDivisor;
    }
    return res;
  }
};

// brute force
// O(N*N*N)
class SolutionBruteForce {
  vector<string> res;
  unordered_map<char, int> m;

public:
  int uniqueLetterString(string s) {
    res = {};
    m = {};
    getAllSubstring(s, res);
    int count = 0;
    for (const auto &val : res) {
      count += countUniqueChars(val);
    }
    return count;
  }

  // O(N*N)
  void getAllSubstring(string s, vector<string> &res) {
    for (int i = 0; i < s.length(); ++i) {
      for (int j = 1; j < s.length() + 1 - i; ++j) {
        res.push_back(s.substr(i, j));
      }
    }
  }

  // O(N)
  int countUniqueChars(string subStr) {
    m = {};
    for (const auto &val : subStr) {
      ++m[val];
    }

    int count = 0;
    for (const auto &val : m) {
      if (val.second == 1) {
        ++count;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.uniqueLetterString("ABC") << endl;
  cout << s.uniqueLetterString("ABA") << endl;
  cout << s.uniqueLetterString("LEETCODE") << endl;
}
