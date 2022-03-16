#include "bits/stdc++.h"

using namespace std;

/**
 * @brief
 *
 * @return the length of LPS
 *
 */
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
        // TODO: it's nothing that the following condition make sure the reamining
        // part is longest palindromic substring
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

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;

  LPSButtonUp *lps2 = new LPSButtonUp();
  cout << lps2->findLPSLength("abdbca") << endl;
  cout << lps2->findLPSLength("cddpd") << endl;
  cout << lps2->findLPSLength("pqr") << endl;

  delete lps2;
}