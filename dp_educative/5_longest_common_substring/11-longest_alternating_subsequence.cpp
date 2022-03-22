#include "bits/stdc++.h"

using namespace std;



// TODO: button up approach
class LAS {


public:
  int findLASLength(const vector<int> &nums) {


  }
};



class LASMap {

  unordered_map<string, int> m;

public:
  int findLASLength(const vector<int> &nums) {
    m = {};
    return max(findLASLength(nums, -1, 0, true),
               findLASLength(nums, -1, 0, false));
  }

  int findLASLength(const vector<int> &nums, int prev, int curr,
                    bool isAscending) {
    if (curr == nums.size()) {
      return 0;
    }

    string key = getKey(prev, curr, isAscending);
    if (!m.count(key)) {
      int c1 = 0, c2 = 0;

      if (isAscending) {
        // if ascending, the next eleemnt should be bigger
        if (prev == -1 || nums[prev] < nums[curr]) {
          c1 = 1 + findLASLength(nums, curr, curr + 1, !isAscending);
        }
      } else {
        // if descending, the next eleemnt should be be smaller
        if (prev == -1 || nums[prev] > nums[curr]) {
          c1 = 1 + findLASLength(nums, curr, curr + 1, !isAscending);
        }
      }

      c2 = findLASLength(nums, prev, curr + 1, isAscending);

      m[key] = max(c1, c2);
    }
    return m[key];
  }

  string getKey(int prev, int curr, bool isAse) {
    return to_string(prev) + "|" + to_string(curr) + "|" +
           to_string(int(isAse));
  }
};

class LASRecursive {

public:
  int findLASLength(const vector<int> &nums) {
    return max(findLASLength(nums, -1, 0, true),
               findLASLength(nums, -1, 0, false));
  }

  int findLASLength(const vector<int> &nums, int prev, int curr,
                    bool isAscending) {
    if (curr == nums.size()) {
      return 0;
    }
    int c1 = 0, c2 = 0;

    if (isAscending) {
      // if ascending, the next eleemnt should be bigger
      if (prev == -1 || nums[prev] < nums[curr]) {
        c1 = 1 + findLASLength(nums, curr, curr + 1, !isAscending);
      }
    } else {
      // if descending, the next eleemnt should be be smaller
      if (prev == -1 || nums[prev] > nums[curr]) {
        c1 = 1 + findLASLength(nums, curr, curr + 1, !isAscending);
      }
    }

    c2 = findLASLength(nums, prev, curr + 1, isAscending);

    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LAS *las = new LAS();
  vector<int> nums = {1, 2, 3, 4};
  cout << las->findLASLength(nums) << endl;
  nums = vector<int>{3, 2, 1, 4};
  cout << las->findLASLength(nums) << endl;
  nums = vector<int>{1, 3, 2, 4};
  cout << las->findLASLength(nums) << endl;

  delete las;
}