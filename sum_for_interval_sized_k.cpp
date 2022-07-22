#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> &ivec, int k) {
  vector<int> res;
  int temp = 0;
  int n = ivec.size();
  for (int i = 0; i < n; ++i) {
    temp += ivec[i];
    // when i >= k-1
    if (i >= k - 1) {
      res.push_back(temp);
      temp -= ivec[i + 1 - k];
    }
  }
  return res;
}

int main() {
  vector<int> ivec{1, 3, 5, 2, 4};
  int k = 3;
  // 9, 10, 11
  for (const auto &val : solution(ivec, k)) {
    cout << val << endl;
  }
}