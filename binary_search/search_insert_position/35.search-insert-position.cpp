/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return l;
  }
};

// @lc code=end





class Solution2 {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
  }
};


// TEST:
int BinarySearch(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1;
    // NOTE: if we using l<r, then we won't be able to search last elem in nums
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    // l return the position which be inserted 
    // return l;
    return -1;
}



int main(int argc, char const *argv[])
{
    vector<int> ivec{1, 2, 3, 6, 8, 9, 12, 15, 16, 19};
    cout << "👉 the size of ivec is " << ivec.size() << endl;
    cout << BinarySearch(ivec, 4) << endl;

    return 0;
}
