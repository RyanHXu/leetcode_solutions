/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution
{
    vector<vector<int>> res;
    unordered_map<int, int> counter;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        int n = nums.size();
        for (const auto val : nums) {
            ++counter[val];
        }
        vector<int> perm;
        backtrack(perm, n);
        return res;
    }
    
    void backtrack(vector<int> &perm, int n)
    {

        if(perm.size() == n){
            res.push_back(perm);
        }else{
            for (const auto val : counter) {
                int key = val.first;
                int value=val.second;
                if (value <=0){
                    continue;
                }
                perm.push_back(key);
                --counter[key];
                backtrack(perm, n);
                perm.pop_back();
                ++counter[key];
            }
        }
    }
};

// @lc code=end


// approach 2, use extral function to check
// pretty straightforward
class Solution2
{
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, n);
        return res;
    }
    bool shouldSwap(vector<int> &nums, int start, int curr){
        for (int i = start; i < curr; ++i) {
          if(nums[i] == nums[curr]){
              return false;
          }
        }
        return true;
    }
    void backtrack(vector<int> &nums, int start, int n)
    {
        if (start == n)
        {
            res.push_back(nums);
        }
        
        for (int i = start; i < n; ++i)
        {
            if (shouldSwap(nums,start,i))
            {
                swap(nums[i], nums[start]);
                backtrack(nums, start + 1, n);
                swap(nums[i], nums[start]);
            }
        }
    }
};



