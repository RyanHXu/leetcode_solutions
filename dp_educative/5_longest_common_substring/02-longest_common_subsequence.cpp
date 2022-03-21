#include "bits/stdc++.h"

using namespace std;


// button up - space optimized
// optimized by 2 row array
// also need a variable to track longest common subsequence
class LCS {

public:
  int findLCSLength(const string &s1, const string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int maxLen = 0;
    vector<vector<int>> dp(2,vector<int>(n2+1,0));
    for (int i = 1; i < n1+1; ++i) {
      for (int j = 1; j <n2+1; ++j) {
        // reset data
        dp[i % 2][j] = 0;
        if(s1[i-1] == s2[j-1]){
          dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
        }else{
          dp[i % 2][j] = max(
            dp[(i - 1) % 2][j], dp[i % 2][j-1]
          );
        }
        maxLen = max(maxLen, dp[i % 2][j]);
      }
    }
    return maxLen;
    }
};


class LCSButtonUp {

public:
  int findLCSLength(const string &s1, const string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for (int i = 1; i < n1+1; ++i) {
      for (int j = 1; j < n2+1; ++j) {
        if(s1[i]==s2[j]){
          dp[i][j] = 1 + dp[i-1][j-1];
        }else{
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[n1][n2];
    }
};

// map
class LCSMap {
  unordered_map<string, int> m;

public:
  int findLCSLength(const string &s1, const string &s2) {
    // reset map new task
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
      // if s1[i]==s2[j], it also means we get the longest common subsequence, then we don't need to skip either begining or ending. we can prove it by math.
      return 1 + findLCSLengthRecursive(s1, s2, i + 1, j + 1);
    }
    int c1 = findLCSLengthRecursive(s1, s2, i + 1, j);
    int c2 = findLCSLengthRecursive(s1, s2, i, j + 1);

    return max(c1, c2);
  }
};


int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  // LCSRecursive *lcs = new LCSRecursive();
  // 3, 5, 6, 5
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
  // abcd(de)ab, abcd(dk)ab
  cout << lcs->findLCSLength("abcdeab", "abcdkab") << endl;
  // lllgl, lllg(ab)l
  cout << lcs->findLCSLength("glllgl", "lllgabl") << endl;

  delete lcs;
}