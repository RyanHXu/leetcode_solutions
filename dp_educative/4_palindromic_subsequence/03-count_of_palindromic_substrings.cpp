#include "bits/stdc++.h"

using namespace std;

class CPS {
public:
  int findCPS(const string &st) {
    int n = st.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;

    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
      count++;
    }

    for (int l = n - 1; l > -1; --l) {
      for (int r = l + 1; r < n; ++r) {
        if (st[l] == st[r]) {
          // if it's a two character string or if the remaining string is a
          // palindrome too
          if (r - l == 1 || dp[l + 1][r - 1]) {
            dp[l][r] = true;
            count++;
          }
        }
      }
    }

    return count;
  }
};

int main(int argc, char *argv[]) {
  CPS *cps = new CPS();
  cout << cps->findCPS("abdbca") << endl;
  cout << cps->findCPS("cdpdd") << endl;
  cout << cps->findCPS("pqr") << endl;

  delete cps;
}