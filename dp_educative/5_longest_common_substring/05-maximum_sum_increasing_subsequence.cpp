using namespace std;

#include <iostream>
#include <vector>

class MSIS {

public:
  int findMSIS(const vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(nums.begin(), nums.end());
    int res = nums[0];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i] && dp[i] < dp[j] + nums[i]) {
          dp[i] = dp[j] + nums[i];
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  MSIS *msis = new MSIS();
  vector<int> nums = {4, 1, 2, 6, 10, 1, 12};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29};
  cout << msis->findMSIS(nums) << endl;

  delete msis;
}