/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// TODO: review it
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // brute force
    int pA = 1;
    int n = nums.size();
    int countZeros = 0;

    for (const auto &val : nums) {
      if (val == 0)
        ++countZeros;
      else
        pA *= val;
    }

    vector<int> res(n, 0);
    // if we have more than 2 zeros, just return 0
    if (countZeros > 1) {
      return res;
    } else if (countZeros == 1) {
      // if we have only one zero, just skip the update operation of the item
      // equal to 0
      for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
          res[i] = pA;
        }
      }
    } else {
      // if don't have zero
      for (int i = 0; i < n; ++i) {
        res[i] = pA / nums[i];
      }
    }
    return res;
  }
};

// @lc code=end



class Solution2 {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    // left[i] store product of array from 0 to i-1
    // right[i] store product of array from n-1 to i+1
    // the result will be left[i]*right[i]

    for (int i = 1; i < n; ++i) {
      res[i] = res[i - 1] * nums[i - 1];
    }

    int R = nums[n-1];

    for (int i = n - 2; i >= 0; --i) {
      res[i] = res[i] * R;
      R *= nums[i];

    }

    return res;
  }
};


// my navie implemention
class Solution_1 {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // brute force
    int pA = 1;
    deque<int> indexOfZeros;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        indexOfZeros.push_back(i);
      } else {
        pA *= nums[i];
      }
    }

    vector<int> res(n, 0);
    // if we have more than 2 zeros, just return 0
    if (indexOfZeros.size() > 1) {
      return res;
    } else if (indexOfZeros.size() == 1) {
      // if we have only one zero, just skip the update operation of the item
      // equal to 0
      for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
          res[i] = pA;
        }
      }
    } else {
      // if don't have zero
      for (int i = 0; i < n; ++i) {
        res[i] = pA / nums[i];
      }
    }

    return res;
  }
};

class Solution3 {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    // left[i] store product of array from 0 to i-1
    // right[i] store product of array from n-1 to i+1
    // the result will be left[i]*right[i]

    for (int i = 1; i < n; ++i) {
      left[i] = left[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
      right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i) {
      nums[i] = left[i] * right[i];
    }
    return nums;
  }
};

// FIXME: if nums contains 0, this solutions won't work
// [-1,1,0,-3,3]
class Solution4 {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // brute force
    int pA = 1;
    for (const auto &val : nums) {
      pA *= val;
    }

    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      res[i] = pA / nums[i];
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> ivec{-1, 1, 0, -3, 3};
  for (const auto &val : s.productExceptSelf(ivec)) {
    cout << val << ' ';
  }
  cout << endl;
  vector<int> ivec2{1,2,3,4};
  for (const auto &val : s.productExceptSelf(ivec2)) {
    cout << val << ' ';
  }
}