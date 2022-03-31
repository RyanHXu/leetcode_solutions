#include "bits/stdc++.h"

using namespace std;

// brute force idea
// try all three operations and iterate s1 and s2
// 1) if s1[i]==s2[j], we recursively compare the remaining part
// 2) if s1[i]!=s2[j], we call delete, insert, replace opetions recursively


// button up
class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // TODO: if s1 is empty
    for (int i1 = 1; i1 < n1+1; ++i1) {
      dp[i1][0] = i1;
    }


    // TODO: if s2 is empty
    for (int i2 = 1; i2 < n2+1; ++i2) {
      dp[0][i2] = i2;
    }


    for (int i = 1; i < n1+1; ++i) {
      for (int j = 1; j < n2+1; ++j) {
        if (s1[i-1] == s2[j-1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
      }
    }

    return dp[n1][n2];
  }
};

class EditDistanceVec {
  vector<vector<int>> dp;

public:
  int findMinOperations(const string &s1, const string &s2) {
    dp = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return findMinOperations(s1, s2, 0, 0);
  }

  int findMinOperations(const string &s1, const string &s2, int i, int j) {

    if (dp[i][j] == -1) {

      if (i == s1.length()) {
        return s2.length() - j;
      }

      if (j == s2.length()) {
        return s1.length() - i;
      }

      int c1 = 0, c2 = 0, c3 = 0;
      if (s1[i] == s2[j]) {
        dp[i][j] = findMinOperations(s1, s2, i + 1, j + 1);
      } else {

        // TODO: DO NOT forget to add else here
        c1 = findMinOperations(s1, s2, i + 1, j);     // perform deletion
        c2 = findMinOperations(s1, s2, i, j + 1);     // perform insertion
        c3 = findMinOperations(s1, s2, i + 1, j + 1); // perform replace

        dp[i][j] = 1 + min(c1, min(c2, c3));
      }
    }

    return dp[i][j];
  }
};


// O(pow(N,m+n))
// N to the pow of (m+n)
class EditDistanceRecursive {

public:
  int findMinOperations(const string &s1, const string &s2) {

    return findMinOperations(s1, s2, 0, 0);
  }

  int findMinOperations(const string &s1, const string &s2, int i, int j) {
    if (i == s1.length()) {
      return s2.length() - j;
    }

    if (j == s2.length()) {
      return s1.length() - i;
    }

    int c1 = 0, c2 = 0, c3 = 0;
    if (s1[i] == s2[j]) {
      return findMinOperations(s1, s2, i + 1, j + 1);
    }

    c1 = 1 + findMinOperations(s1, s2, i + 1, j);     // perform deletion
    c2 = 1 + findMinOperations(s1, s2, i, j + 1);     // perform insertion
    c3 = 1 + findMinOperations(s1, s2, i + 1, j + 1); // perform replace

    return min(c1, min(c2, c3));
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  // 1, 2, 3, 0
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;
  cout << editDisatnce->findMinOperations("passpot", "passpot") << endl;

  delete editDisatnce;
}