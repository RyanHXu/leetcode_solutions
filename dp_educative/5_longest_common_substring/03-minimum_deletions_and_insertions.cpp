#include "bits/stdc++.h"

using namespace std;

class MDI {

public:
  void findMDI(const string &s1, const string &s2) {
      int n1 = s1.size();
      int n2 = s2.size();
      vector<vector<int>> dp(2,vector<int>(n2+1,0));
      int maxLen = 0;
      for (int i = 1; i < n1+1; ++i) {
        for (int j = 1; j < n2+1; ++j) {
          // reset data
          dp[i % 2][j] = 0;
          if(s1[i-1]==s2[j-1]){
              dp[i % 2][j] = 1 + dp[(i - 1) %2 ][j - 1];
          }else{
              dp[i % 2][j] = max(
                  dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
          }
          maxLen= max(dp[i % 2][j], maxLen);
        }
      }
      cout << "maxLen: " << maxLen << endl;

      cout << "Minimum deletions needed: " << (n1-maxLen) << endl;
      cout << "Minimum insertions needed: " << (n2-maxLen ) << endl;
  }
};

int main(int argc, char *argv[]) {
  MDI *mdi = new MDI();
  mdi->findMDI("abc", "fbc");
  mdi->findMDI("abdca", "cbda");
  mdi->findMDI("passport", "ppsspt");

  delete mdi;
}