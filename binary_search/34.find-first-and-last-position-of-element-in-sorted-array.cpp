/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        int lower = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        int len = nums.size();

        if(lower == len || nums[lower] != target){
            return vector<int>{-1, -1};
        }

        return {lower, upper};
    }
};
// @lc code=end

