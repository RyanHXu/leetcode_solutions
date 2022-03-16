#include "bits/stdc++.h"

using namespace std;

class Fibonacci {
  vector<int> dp;

public:
  int CalculateFibonacci(int n) {
    dp = vector<int>(n + 1, -1);
    return CalculateFibonacciTopDown(n);
  }

  int CalculateFibonacciTopDown(int n) {
    if (n < 2) {
      return n;
    }
    if (dp[n] == -1) {
      dp[n] =
          CalculateFibonacciTopDown(n - 2) + CalculateFibonacciTopDown(n - 1);
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