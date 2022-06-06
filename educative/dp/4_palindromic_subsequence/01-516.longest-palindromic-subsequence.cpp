/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int i = n - 1; i > -1; --i) {
      for (int j = i + 1; j < n; ++j) {
        // case 1: start == end
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          // skip one element eigher from the beginning or the end
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end

// Top Down
class SolutionTopDown {
  vector<vector<int>> dp;

 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    return longestPalindromeSubseqRecursive(s, 0, n - 1);
  }

  int longestPalindromeSubseqRecursive(string &st, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }
    if (dp[l][r] == -1) {
      // case 1:
      if (st[l] == st[r]) {
        dp[l][r] = 2 + longestPalindromeSubseqRecursive(st, l + 1, r - 1);
      } else {
        // case 2: skip one element either from beginning or the end
        int c1 = longestPalindromeSubseqRecursive(st, l + 1, r);
        int c2 = longestPalindromeSubseqRecursive(st, l, r - 1);
        dp[l][r] = max(c1, c2);
      }
    }

    return dp[l][r];
  }
};

// Time Limit Exceeded
class SolutionRecursion {
 public:
  int longestPalindromeSubseq(string s) {
    return longestPalindromeSubseqRecursive(s, 0, s.size() - 1);
  }

  int longestPalindromeSubseqRecursive(string &st, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }
    if (st[l] == st[r]) {
      return 2 + longestPalindromeSubseqRecursive(st, l + 1, r - 1);
    }

    int c1 = longestPalindromeSubseqRecursive(st, l + 1, r);
    int c2 = longestPalindromeSubseqRecursive(st, l, r - 1);

    return max(c1, c2);
  }
};

// Time Limit Exceeded
class SolutionRecursion2 {
  unordered_map<string, int> m;

 public:
  int longestPalindromeSubseq(string s) {
    return longestPalindromeSubseqRecursive(s, 0, s.size() - 1);
  }

  int longestPalindromeSubseqRecursive(string &st, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }

    string key = getKey(l, r);

    if (!m.count(key)) {
      if (st[l] == st[r]) {
        m[key] = 2 + longestPalindromeSubseqRecursive(st, l + 1, r - 1);
      } else {
        int c1 = longestPalindromeSubseqRecursive(st, l + 1, r);
        int c2 = longestPalindromeSubseqRecursive(st, l, r - 1);
        m[key] = max(c1, c2);
      }
    }
    return m[key];
  }

  string getKey(int l, int r) { return to_string(l) + "|" + to_string(r); }
};

int main() {
  SolutionRecursion2 s;

  // 6
  cout << s.longestPalindromeSubseq("fffggg") << endl;
  // 494
  // cout << s.longestPalindromeSubseq(
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
  //             "ffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
  //             "ggggggggggggggggggggggggggg")
  //      << endl;
}
