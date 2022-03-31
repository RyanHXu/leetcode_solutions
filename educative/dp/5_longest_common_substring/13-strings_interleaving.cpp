#include "bits/stdc++.h"

using namespace std;

// there are three variables, i1, i2, i3, we need 3d array.

class SI {

public:
  bool findSI(const string &m, const string &n, const string &p) {
    int n1 = m.length(), n2 = n.length(), n3 = p.length();
    if (n3 != n1 + n2)
      return false;

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, 0));
    for (int i = 0; i < n1 + 1; ++i) {
      for (int j = 0; j < n2 + 1; ++j) {
        // m and n are both empty,then p must have been empty too
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0 && n[j - 1] == p[i + j - 1]) {
            // if m is empty, we need to check the interleaving wtih n only
          dp[i][j] = dp[i][j - 1];
        } else if (j == 0 && m[i - 1] == p[i + j - 1]) {
            // if n is empty, we need to check the interleaving with m only
          dp[i][j] = dp[i - 1][j];
        } else {
            // if the letter of m and p match, we take whatever is mathed till n1-1
          if (i > 0 && m[i - 1] == p[i + j - 1])
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            // if the letter of n and p match, we take whatever is mathed till n2-1
          if (j > 0 && n[j - 1] && n[j - 1] == p[i + j - 1])
            dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
      }
    }
    return dp[n1][n2];
  }
};

class SIMap {
  unordered_map<string, bool> m;

public:
  string getKey(int i1, int i2, int i3) {
    // TODO: reset m for every time
    m = {};
    return to_string(i1) + "|" + to_string(i2) + "|" + to_string(i3);
  }
  bool findSI(const string &m, const string &n, const string &p) {
    return findSI(m, n, p, 0, 0, 0);
  }

  bool findSI(const string &s1, const string &s2, const string &s3, int i1,
              int i2, int i3) {
    if (i3 == s3.length() && i1 == s1.length() && i2 == s2.length()) {
      return true;
    }

    if (i3 == s3.length()) {
      return false;
    }

    string key = getKey(i1, i2, i3);
    if (!m.count(key)) {
      bool b1 = false, b2 = false;

      if (i1 < s1.length() && s1[i1] == s3[i3]) {
        b1 = findSI(s1, s2, s3, i1 + 1, i2, i3 + 1);
      }
      if (i2 < s2.length() && s2[i2] == s3[i3]) {
        b2 = findSI(s1, s2, s3, i1, i2 + 1, i3 + 1);
      }
      m[key] = b1 || b2;
    }

    return m[key];
  }
};

class SIRecursive {

public:
  bool findSI(const string &m, const string &n, const string &p) {
    return findSI(m, n, p, 0, 0, 0);
  }

  bool findSI(const string &s1, const string &s2, const string &s3, int i1,
              int i2, int i3) {
    if (i3 == s3.length() && i1 == s1.length() && i2 == s2.length()) {
      return true;
    }

    if (i3 == s3.length()) {
      return false;
    }
    bool b1 = false, b2 = false;

    if (i1 < s1.length() && s1[i1] == s3[i3]) {
      b1 = findSI(s1, s2, s3, i1 + 1, i2, i3 + 1);
    }
    if (i2 < s2.length() && s2[i2] == s3[i3]) {
      b2 = findSI(s1, s2, s3, i1, i2 + 1, i3 + 1);
    }

    return b1 || b2;
  }
};

// FIXME:
// https://leetcode.com/problems/interleaving-string/
// two pointers doesn't work here, check leetcode case 1
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {

    int i1 = 0, i2 = 0, i3 = 0;
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

    if (n3 <= n1 + n2) {
      while (i3 < n3) {
        int temp = i3;
        if (i1 < n1 && s3[i3] == s1[i1]) {
          ++i3;
          ++i1;
        }
        if (i2 < n2 && s3[i3] == s2[i2]) {
          ++i3;
          ++i2;
        }

        if (i3 == temp) {
          return false;
        }
      }
    }

    return i3 == n3;
  }
};

int main(int argc, char *argv[]) {
  SI *si = new SI();
  cout << si->findSI("abd", "cef", "abcdef") << endl;
  cout << si->findSI("abd", "cef", "adcbef") << endl;
  cout << si->findSI("abc", "def", "abdccf") << endl;
  cout << si->findSI("abcdef", "mnop", "mnaobcdepf") << endl;

  delete si;
}