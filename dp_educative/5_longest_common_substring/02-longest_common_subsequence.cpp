#include "bits/stdc++.h"

using namespace std;

// map
class LCS {
  unordered_map<string, int> m;

public:
  int findLCSLength(const string &s1, const string &s2) {
    m = {};
    return findLCSLengthTopDown(s1, s2, 0, 0);
  }

  int findLCSLengthTopDown(const string &s1, const string &s2, int i, int j) {
    if (i == s1.size() || j == s2.size()) {
      return 0;
    }
    // if we didn't process dp[i][j] before
    string key = to_string(i) + "|" + to_string(j);
    if (m.find(key) == m.end()) {
      if (s1[i] == s2[j]) {
        m[key] = 1 + findLCSLengthTopDown(s1, s2, i + 1, j + 1);
      } else {
        int c1 = findLCSLengthTopDown(s1, s2, i + 1, j);
        int c2 = findLCSLengthTopDown(s1, s2, i, j + 1);
        m[key] = max(c1, c2);
      }
    }

    return m[key];
  }
};

// 2-d array
class LCS2DVec {
  vector<vector<int>> dp;

public:
  int findLCSLength(const string &s1, const string &s2) {
    dp = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
    return findLCSLengthTopDown(s1, s2, 0, 0);
  }

  int findLCSLengthTopDown(const string &s1, const string &s2, int i, int j) {
    if (i == s1.size() || j == s2.size()) {
      return 0;
    }
    // if we didn't process dp[i][j] before
    if (dp[i][j] == -1) {
      if (s1[i] == s2[j]) {
        dp[i][j] = 1 + findLCSLengthTopDown(s1, s2, i + 1, j + 1);
      } else {
        int c1 = findLCSLengthTopDown(s1, s2, i + 1, j);
        int c2 = findLCSLengthTopDown(s1, s2, i, j + 1);
        dp[i][j] = max(c1, c2);
      }
    }

    return dp[i][j];
  }
};

class LCSRecursive {
public:
  int findLCSLength(const string &s1, const string &s2) {

    return findLCSLengthRecursive(s1, s2, 0, 0);
  }

  int findLCSLengthRecursive(const string &s1, const string &s2, int i, int j) {
    if (i > s1.size() - 1 || j > s2.size()) {
      return 0;
    }

    if (s1[i] == s2[j]) {
      return 1 + findLCSLengthRecursive(s1, s2, i + 1, j + 1);
    }
    int c1 = findLCSLengthRecursive(s1, s2, i + 1, j);
    int c2 = findLCSLengthRecursive(s1, s2, i, j + 1);

    return max(c1, c2);
  }
};


int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  // 3, 5, 6, 4
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
  cout << lcs->findLCSLength("abcdeab", "abcdkab") << endl;
  cout << lcs->findLCSLength("glllgl", "llllg") << endl;

  delete lcs;
}