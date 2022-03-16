#include "bits/stdc++.h"

using namespace std;



class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }

    for (int c = 1; c < sum+1; ++c) {
        if(num[0]==c){
            dp[0][c] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < sum+1; ++j) {
        // exclude
        dp[i][j] = dp[i - 1][j];
        if(num[i]<=j){
            dp[i][j] += dp[i - 1][j - num[i]];
        }
      }
    }
    return dp[n - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}