/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// dp & prefix
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      int n = nums.size();
      if(k==1){
          return nums;
      }
      vector<int> left(n);
      left[0] = nums[0];
      vector<int> right(n);
      right[n - 1] = nums[n - 1];
      vector<int> res(n-k+1);
      for (int i = 1; i < n; ++i) {
        // l to r
        if(i%k ==0){
            left[i] = nums[i];
        }else{
            left[i] = max(left[i - 1], nums[i]);
        }
        // r to l
        int j = n - i - 1;
        if((j+1)%k ==0){
            right[j] = nums[j];
        }else{
            right[j] = max(right[j + 1], nums[j]);
        }
      }
      for (int i = 0; i < n-k+1; ++i) {
          res[i] = max(left[i + k - 1], right[i]);
      }
      return res;
  }
};
// @lc code=end

// priority_queue
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> res;
    int l = 0, r = 0;
    while (r < nums.size()) {
      pq.push({nums[r], r});
      if (r - l + 1 < k) {
        ++r;
      } else if (r - l + 1 == k) {
        while (pq.top().second < l) {
          pq.pop();
        }
        res.push_back(pq.top().first);
        ++l;
        ++r;
      }
    }
    return res;
  }
};

// brute force
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int res = INT32_MIN;
    vector<int> ans;

    int i = 0, j = 0;
    for (; j < nums.size(); ++j) {
      if (j < k) {
        res = max(res, nums[j]);
      }
      if (j >= k) {
        ans.push_back(res);
        ++i;
        res = *max_element(nums.begin() + i, nums.begin() + i + k);
      }
    }
    res = *max_element(nums.begin() + i, nums.end());
    ans.push_back(res);
    return ans;
  }
};

int main() {
  vector<int> ivec{1, 3, -1, -3, 5, 3, 6, 7};
  Solution s;
  for (const auto val : s.maxSlidingWindow(ivec, 3)) {
    cout << val << ' ';
  }
}