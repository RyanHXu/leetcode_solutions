/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int left = 0, right = 0, maxLen = 0;
    unordered_map<int, int> m;
    while (right < fruits.size()) {
      ++m[fruits[right]];

      while (m.size() > 2) {
        --m[fruits[left]];
        if (m[fruits[left]] == 0) {
          m.erase(fruits[left]);
        }
        ++left;
      }
      maxLen = max(maxLen, right - left + 1);
      ++right;
    }
    return maxLen;
  }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    vector<int> ivec{0,1,2,2,3,3,3,3};
    Solution s;
    cout << s.totalFruit(ivec) << endl;
    return 0;
}
