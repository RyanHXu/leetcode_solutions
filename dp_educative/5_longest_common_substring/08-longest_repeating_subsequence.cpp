using namespace std;

#include <iostream>
#include <vector>

class LBS {

public:
  int findLBSLength(const vector<int> &nums) {
    vector<vector<int>> lds(nums.size(), vector<int>(nums.size() + 1, -1));
    vector<vector<int>> ldsRev(nums.size(), vector<int>(nums.size() + 1, -1));

    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++) {
      int c1 = findLDSLength(lds, nums, i, -1);
      int c2 = findLDSLengthReverse(ldsRev, nums, i, -1);
      maxLength = max(maxLength, c1 + c2 - 1);
    }

    return maxLength;
  }

private:
  // find the longest decreasing subsequence from currentIndex till the end of the array
  int findLDSLength(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex,
                    int previousIndex) {
    if (currentIndex == nums.size()) {
      return 0;
    }

    if (dp[currentIndex][previousIndex + 1] == -1) {
      // include nums[currentIndex] if it is smaller than the previous number
      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
        c1 = 1 + findLDSLength(dp, nums, currentIndex + 1, currentIndex);
      }

      // excluding the number at currentIndex
      int c2 = findLDSLength(dp, nums, currentIndex + 1, previousIndex);

      dp[currentIndex][previousIndex + 1] = max(c1, c2);
    }

    return dp[currentIndex][previousIndex + 1];
  }

  // find the longest decreasing subsequence from currentIndex till the beginning of the array
  int findLDSLengthReverse(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex,
                           int previousIndex) {
    if (currentIndex < 0) {
      return 0;
    }

    if (dp[currentIndex][previousIndex + 1] == -1) {
      // include nums[currentIndex] if it is smaller than the previous number
      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
        c1 = 1 + findLDSLengthReverse(dp, nums, currentIndex - 1, currentIndex);
      }

      // excluding the number at currentIndex
      int c2 = findLDSLengthReverse(dp, nums, currentIndex - 1, previousIndex);

      dp[currentIndex][previousIndex + 1] = max(c1, c2);
    }
    return dp[currentIndex][previousIndex + 1];
  }
};

int main(int argc, char *argv[]) {
  LBS *lbs = new LBS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lbs->findLBSLength(nums) << endl;
  nums = vector<int>{4, 2, 5, 9, 7, 6, 10, 3, 1};
  cout << lbs->findLBSLength(nums) << endl;

  delete lbs;
}