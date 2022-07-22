#include "bits/stdc++.h"

using namespace std;

// https://www.1point3acres.com/bbs/thread-796903-1-1.html
// https://algo.monster/problems/amazon_oa_max_profit
int solution(vector<int> profit, int k) {
  int n = profit.size();
  int curr = 0;
  for (int i = 0; i < k; ++i) {
    curr += profit[i];
    curr += profit[n / 2 + i];
  }
  int output = curr;
  for (int i = 1; i < n / 2; ++i) {
    curr = curr - profit[i - 1] + profit[i + k - 1];
    curr = curr - profit[(n / 2 + i - 1) % n] + profit[(n / 2 + i + k - 1) % n];
    output = max(curr, output);
  }
  return output;
}
int main() { 
    cout << solution({1, 5, 1, 3, 7, -3}, 2) << endl; }