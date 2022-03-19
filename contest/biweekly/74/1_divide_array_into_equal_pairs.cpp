#include "bits/stdc++.h"

using namespace std;

// FIXME: bitwise or doesn't work here
// class Solution {
// public:
//   bool divideArray(vector<int> &nums) {
//     int a = 0;
//     for (const auto &val : nums) {
//       a ^= val;
//     }
//     return a == 0;
//   }
// };

// bitwise or doesn't work here
class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> m;
    for (const auto &val : nums) {
      ++m[val];
    }
    for (const auto &val : m) {
      if (val.second % 2 != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> ivec{9,  9,  19, 10, 9,  12, 2,  12, 3,  3,  11, 5,  8,  4,  13,
                   6,  2,  11, 9,  19, 11, 15, 9,  17, 15, 12, 5,  14, 12, 16,
                   18, 16, 10, 3,  8,  9,  16, 20, 2,  4,  16, 12, 11, 14, 20,
                   16, 2,  18, 17, 20, 3,  13, 16, 17, 1,  1,  11, 20, 20, 4};

  for (const auto &val : ivec) {
    cout << val << ' ';
  }

  cout << endl;
  cout << s.divideArray(ivec) << endl;
  int a = 0;
  a ^= 10;

  a ^= 10;
  a ^= 10;
  // 1010

  cout << a << endl;
}