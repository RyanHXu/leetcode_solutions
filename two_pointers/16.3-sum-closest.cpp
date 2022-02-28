/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include "bits/stdc++.h"

using namespace std;


// NOTE: three pointers
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT32_MAX;

        for (int i = 0; i < n && diff!=0; ++i) {
            int l = i + 1;
            int r = n - 1;
            while (l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target-sum) < abs(diff)){
                    diff = target - sum;
                }
                if (sum<target){
                    ++l;
                }else{
                    --r;
                }
            }
        }
        return target - diff;
    }
};
// @lc code=end


// NOTE: brute force
class Solution2 {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    int res = INT32_MAX / 2;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          int temp = nums[i] + nums[j] + nums[k];
          if (abs(temp - target) < abs(res - target))
            res = temp;
        }
      }
    }
    return res;
  }
};

int main() { cout << INT16_MAX; }