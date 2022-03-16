#include "bits/stdc++.h"

using namespace std;


class Fibonacci {
public:
  int CalculateFibonacci(int n) {
      vector<int> dp(n + 1, 0);
      dp[1] = 1;
      for (int i = 2; i < n+1; ++i) {
          dp[i] = dp[i - 1] + dp[i - 2];
      }
      return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Fibonacci *fib = new Fibonacci();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  delete fib;
}