/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include "bits/stdc++.h"

using namespace std;



// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
        // if we didn't find, restore the another element's value with current index
          if(m.find(nums[i])==m.end()){
            m[target - nums[i]] = i;
          }else{
            // when we found second element, we return current index
              return {m[nums[i]], i};
          }
        }
        return {};
    }
};
// @lc code=end



