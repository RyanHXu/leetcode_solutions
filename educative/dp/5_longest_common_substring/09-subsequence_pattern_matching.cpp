#include "bits/stdc++.h"

using namespace std;

class SPM {

public:
  int findSPMCount(const string &str, const string &pat) {
    int n1 = str.length();
    int n2 = pat.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2, 0));

    for (int i = 0; i < n1 + 1; ++i) {
      dp[i][0] = 1;
    }

    // TODO: review it again
    for (int i = 1; i < n1 + 1; ++i) {
      for (int j = 1; j < n2 + 1; ++j) {
        if (str[i - 1] == pat[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
        dp[i][j] += dp[i - 1][j];
      }
    }
    return dp[n1][n2];
  }
};

class SPMTopDown {
  vector<vector<int>> dp;

public:
  int findSPMCount(const string &str, const string &pat) {

    dp = vector<vector<int>>(str.length(), vector<int>(pat.length(), -1));

    return findSPMCount(str, pat, 0, 0);
  }

  int findSPMCount(const string &str, const string &pat, int i, int j) {

    if (j == pat.length()) {
      return 1;
    }
    if (i == str.length()) {
      return 0;
    }

    if (dp[i][j] == -1) {
      int c1 = 0, c2 = 0;

      if (str[i] == pat[j]) {
        // recursively match for the remaining lengths of the pattern and the
        // string.
        c1 = findSPMCount(str, pat, i + 1, j + 1);
      }
      // skip the str[i]
      c2 = findSPMCount(str, pat, i + 1, j);
      dp[i][j] = c1 + c2;
    }
    return dp[i][j];
  }
};

/*
A basic brute-force solution could be to try all the subsequences of the given
string to count all that match the given pattern. We can match the pattern with
the given string one character at a time, so we can do two things at any step:

1) If the pattern has a matching character with the string, we can recursively
match for the remaining lengths of the pattern and the string. 2) At every step,
we can always skip a character from the string to try to match the remaining
string with the pattern. So we can start a recursive call by skipping one
character from the string.
*/
class SPMRecursive {
public:
  int findSPMCount(const string &str, const string &pat) {
    return findSPMCountRecursive(str, pat, 0, 0);
  }

  int findSPMCountRecursive(const string &str, const string &pat, int i,
                            int j) {

    if (j == pat.length()) {
      return 1;
    }
    if (i == str.length()) {
      return 0;
    }
    int c1 = 0, c2 = 0;

    if (str[i] == pat[j]) {
      // recursively match for the remaining lengths of the pattern and the
      // string.
      c1 = findSPMCountRecursive(str, pat, i + 1, j + 1);
    }
    // skip the str[i]
    c2 = findSPMCountRecursive(str, pat, i + 1, j);
    return c1 + c2;
  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}