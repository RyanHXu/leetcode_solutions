/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include "bits/stdc++.h"

using namespace std;


// https://www.youtube.com/watch?v=StH5vntauyQ
// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int count = 0;
    auto sit = cbegin(height);
    auto eit = cend(height);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      // max_element [sit, sit+i+1)
      int l = *max_element(sit, sit + i + 1);
      int r = *max_element(sit + i, eit);
      res += min(l, r) - height[i];
    }
    return res;
  }
};
// @lc code=end




class Solution2 {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int count = 0;
    auto sit = cbegin(height);
    auto eit = cend(height);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      // max_element [sit, sit+i+1)
      int l = *max_element(sit, sit + i + 1);
      int r = *max_element(sit + i, eit);
      res += min(l, r) - height[i];
    }
    return res;
  }
};
int main(){
    Solution s;
    vector<int> ivec{0,1,0,2,1,0,1,3,2,1,2,1};
    auto bit= cbegin(ivec);
    cout << *(bit+1) << endl;
    cout << s.trap(ivec) << endl;
}
