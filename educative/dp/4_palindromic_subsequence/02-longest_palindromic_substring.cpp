#include "bits/stdc++.h"

using namespace std;

/**
 * @brief
 *
 * @return the length of LPS
 *
 */

class LPSMap {
  unordered_map<string, int> m;

public:
  int findLPSLength(const string &st) {
    m = {};
    int n = st.size();
    return findLPSLengthRecursion(st, 0, n - 1);
  }

private:
  string getKey(int l, int r) { return to_string(l) + "|" + to_string(r); }
  int findLPSLengthRecursion(const string &st, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }
    string key = getKey(l, r);
    if (!m.count(key)) {
      // case 1: start == end
      int c1 = 0, c2 = 0, c3 = 0;
      if (st[l] == st[r]) {
        // TODO: it's nothing that the following condition make sure the
        // reamining part is longest palindromic substring
        int remainingLength = r - l - 1;
        if (remainingLength == findLPSLengthRecursion(st, l + 1, r - 1)) {
          c1 = 2 + remainingLength;
        }
        // c1 = findLPSLengthRecursion(st, l + 1, r - 1);
      }
      c2 = findLPSLengthRecursion(st, l + 1, r);
      c3 = findLPSLengthRecursion(st, l, r - 1);
      m[key] = max(c1, max(c2, c3));
    }

    return m[key];
  }
};

// topdown
class LPS {
  vector<vector<int>> dp;

public:
  int findLPSLength(const string &st) {
    int n = st.size();
    dp = vector<vector<int>>(n, (vector<int>(n, -1)));
    return findLPSLengthRecursion(st, 0, n - 1);
  }

private:
  int findLPSLengthRecursion(const string &st, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }
    if (dp[l][r] == -1) {
      // case 1: start == end
      int c1 = 0, c2 = 0, c3 = 0;
      if (st[l] == st[r]) {
        int remainingLength = r - l - 1;
        // TODO: it's nothing that the following condition make sure the
        // reamining part is longest palindromic substring
        if (remainingLength == findLPSLengthRecursion(st, l + 1, r - 1)) {
          c1 = 2 + remainingLength;
        }
      }
      c2 = findLPSLengthRecursion(st, l + 1, r);
      c3 = findLPSLengthRecursion(st, l, r - 1);
      dp[l][r] = max(c1, max(c2, c3));
    }

    return dp[l][r];
  }
};

// button up
class LPSButtonUp {
public:
  int findLPSLength(const string &st) {
    int n = st.size();
    vector<vector<bool>> dp(n, (vector<bool>(n, false)));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }

    int maxLen = 1;
    for (int l = n - 1; l > -1; --l) {
      for (int r = l + 1; r < n; ++r) {
        if (st[l] == st[r]) {
          if (r - l == 1 || dp[l + 1][r - 1]) {
            dp[l][r] = true;
            maxLen = max(maxLen, r - l + 1);
          }
        }
      }
    }

    return maxLen;
  }
};

// TODO: followup, could you return LPS substring,instead of return its length,
class LPSButtonUpF1 {
public:
  string findLPSLength(const string &st) {
    int n = st.size();
    vector<vector<bool>> dp(n, (vector<bool>(n, false)));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }

    int maxLen = 1;
    int start = 0;
    for (int l = n - 1; l > -1; --l) {
      for (int r = l + 1; r < n; ++r) {
        // If the element at the startIndex matches the element at the endIndex,
        // we will further check if the remaining substring (from startIndex+1
        // to endIndex-1) is a substring too.
        if (st[l] == st[r]) {
          if (r - l == 1 || dp[l + 1][r - 1]) {
            dp[l][r] = true;
            if (maxLen < r - l + 1) {
              start = l;
              maxLen = r - l + 1;
            }
          }
        }
      }
    }
    return st.substr(start, maxLen);
  }
};

int main(int argc, char *argv[]) {
  cout << "top down with memo" << endl;
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;

  cout << "buttton up" << endl;
  LPSButtonUp *lps2 = new LPSButtonUp();
  cout << lps2->findLPSLength("abdbca") << endl;
  cout << lps2->findLPSLength("cddpd") << endl;
  cout << lps2->findLPSLength("pqr") << endl;

  delete lps2;

  cout << "buttton up - return substring" << endl;
  LPSButtonUpF1 *lps3 = new LPSButtonUpF1();
  // a
  // ca
  // a
  cout << lps3->findLPSLength("abdbca") << endl;
  cout << lps3->findLPSLength("cddpd") << endl;
  cout << lps3->findLPSLength("pqr") << endl;

  delete lps3;

  LPSMap *lpsM = new LPSMap();
  cout << lpsM->findLPSLength("abdbca") << endl;
  cout << lpsM->findLPSLength("cddpd") << endl;
  cout << lpsM->findLPSLength("pqr") << endl;

  delete lpsM;
}