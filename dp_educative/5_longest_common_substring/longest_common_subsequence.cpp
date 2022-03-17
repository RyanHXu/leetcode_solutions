#include "bits/stdc++.h"

using namespace std;

// TODO:
// The three changing values to our recursive function are the two indexes (i1
// and i2) and the ‘count’. Therefore, we can store the results of all
// subproblems in a three-dimensional array. (Another alternative could be to
// use a hash-table whose key would be a string (i1 + “|” i2 + “|” + count)).

// hash
class LCS {
  unordered_map<string,int> m;

public:
  int findLCSLength(const string &s1, const string &s2) {
    int maxLen = min(s1.size(), s2.size());

    return findLCSLengthRecursion(s1, s2);
  }

  int findLCSLengthRecursion(const string &s1, const string &s2, int count = 0,
                             int i = 0, int j = 0) {
    if (i == s1.size() || j == s2.size()) {
      return count;
    }
    string key = to_string(i) + "|" + to_string(j) + "|" + to_string(count);
    if (m.find(key)==m.end()) {
      int c1 = count, c2 = 0, c3 = 0;
      if (s1[i] == s2[j]) {
        c1 = findLCSLengthRecursion(s1, s2, count + 1, i + 1, j + 1);
      }
      c2 = findLCSLengthRecursion(s1, s2, 0, i + 1, j);
      c3 = findLCSLengthRecursion(s1, s2, 0, i, j + 1);
      m[key] = max(c1, max(c2, c3));
    }
    return m[key];
  }
};

// three-dimensional array
class LCS3DVec {
  vector<vector<vector<int>>> dp;

public:
  int findLCSLength(const string &s1, const string &s2) {
    int maxLen = min(s1.size(), s2.size());
    dp = vector<vector<vector<int>>>(
        s1.size(), (vector<vector<int>>(s2.size(), vector<int>(maxLen, -1))));
    return findLCSLengthRecursion(s1, s2);
  }

  int findLCSLengthRecursion(const string &s1, const string &s2, int count = 0,
                             int i = 0, int j = 0) {
    if (i == s1.size() || j == s2.size()) {
      return count;
    }
    if (dp[i][j][count] == -1) {
      int c1 = count, c2 = 0, c3 = 0;
      if (s1[i] == s2[j]) {
        c1 = findLCSLengthRecursion(s1, s2, count + 1, i + 1, j + 1);
      }
      c2 = findLCSLengthRecursion(s1, s2, 0, i + 1, j);
      c3 = findLCSLengthRecursion(s1, s2, 0, i, j + 1);
      dp[i][j][count] = max(c1, max(c2, c3));
    }
    return dp[i][j][count];
  }
};

class LCSRecursion {
public:
  int findLCSLength(const string &s1, const string &s2) {
    return findLCSLengthRecursion(s1, s2);
  }

  int findLCSLengthRecursion(const string &s1, const string &s2, int count = 0,
                             int i = 0, int j = 0) {
    if (i == s1.size() || j == s2.size()) {
      return count;
    }
    if (s1[i] == s2[j]) {
      count = findLCSLengthRecursion(s1, s2, count + 1, i + 1, j + 1);
    }
    int c1 = findLCSLengthRecursion(s1, s2, 0, i + 1, j);
    int c2 = findLCSLengthRecursion(s1, s2, 0, i, j + 1);
    return max(count, max(c1, c2));
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
//   cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
//   cout << lcs->findLCSLength("glll", "lll") << endl;

  delete lcs;
}