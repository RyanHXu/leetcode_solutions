#include "bits/stdc++.h"

using namespace std;


class Solution {
        vector<int> res;

public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
          if(nums[i] == key){
              res.push_back(i);
          }
        }

        if(res.size()==0){
            return {};
        }

        for (int i = 0; i < nums.size(); ++i) {
          if(isValid(i,k)){
              ans.push_back(i);
          }
        }
        return ans;
    }

    bool isValid(int index, int k){
        for (const auto& val : res) {
            if(abs(index - val) <= k){
                return true;
            }
        }
        return false;
    }
};