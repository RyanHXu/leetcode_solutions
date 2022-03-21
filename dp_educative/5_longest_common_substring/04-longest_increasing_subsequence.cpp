#include "bits/stdc++.h"
// #include "gtest/gtest.h"

using namespace std;

// for any steps, we have two options
// 1): If the current number is greater than the previous number that we
// included, we can increment our count and make a recursive call for the
// remaining array. 2): We can skip the current number to make a recursive call
// for the remaining arr

class LIS {

    unordered_map<string, int> m;

public:
  int findLISLength(const vector<int> &nums) {
    return findLISLengthRecursive(nums, 0, -1);
  }

  int findLISLengthRecursive(const vector<int> &nums, int curr, int prev) {
    string key = getKey(curr, prev);
    if(m.count(key))
      return m[key];

    // base check
    if (curr == nums.size()) {
      return 0;
    }

    int c1 = 0, c2 = 0;

    // include nums[currentIndex] if it is larger than the last included number
    if (prev == -1 || nums[curr] > nums[prev]) {
      c1 = 1 + findLISLengthRecursive(nums, curr + 1, curr);
    }

    // excluding the number at currentIndex
    c2 = findLISLengthRecursive(nums, curr + 1, prev);
    m[key] = max(c1, c2);
    return m[key];
    
  }

  string getKey(int curr, int prev){
    return to_string(curr) + "|" + to_string(prev);
  }
};


class LISRecursion {

public:
  int findLISLength(const vector<int> &nums) {
    return findLISLengthRecursive(nums, 0, -1);
  }

  int findLISLengthRecursive(const vector<int> &nums, int curr, int prev) {
    // base check
    if (curr == nums.size()) {
      return 0;
    }

    int c1 = 0, c2 = 0;

    // include nums[currentIndex] if it is larger than the last included number
    if (prev == -1 || nums[curr] > nums[prev]) {
      c1 = 1 + findLISLengthRecursive(nums, curr + 1, curr);
    }

    // excluding the number at currentIndex
    c2 = findLISLengthRecursive(nums, curr + 1, prev);
    return max(c1, c2);
  }
};

// namespace gtest {
// TEST(SolutionTest, CheckSolutionCorrectness) {
//   LIS *lis = new LIS();
//   EXPECT_EQ(5, lis->findLISLength({4, 2, 3, 6, 10, 1, 12}));
//   EXPECT_EQ(4, lis->findLISLength({-4, 10, 3, 7, 15}));
// }
// } // namespace gtest

// int main(int argc, char *argv[]) {
//   ::testing::InitGoogleTest();
//   return RUN_ALL_TESTS();
// }

int main(int argc, char *argv[]) {
  LIS *lis = new LIS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lis->findLISLength(nums) << endl; // 5
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << lis->findLISLength(nums) << endl; // 4

  delete lis;
}
