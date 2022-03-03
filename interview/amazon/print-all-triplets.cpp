// https://www.geeksforgeeks.org/print-all-triplets-with-given-sum/

#include "bits/stdc++.h"

using namespace std;

// brute force
// nums.size() >=3
void findTriplets(vector<int> nums, int target) {
  int n = nums.size();
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (nums[i] + nums[j] + nums[k] == target) {
          cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
        }
      }
    }
  }
}

void findTripletsTwoPinters(vector<int> nums, int target) {
  int n = nums.size();

  for (int i = 0; i < n - 2; ++i) {
    unordered_set<int> s;
    for (int j = i + 1; j < n; ++j) {
      int x = target - nums[i] - nums[j];
      if (s.find(x) != s.end()) {
        cout << x << " " << nums[i] << " " << nums[j] << " " << endl;
      } else {
        s.insert(nums[j]);
      }
    }
  }
}

int main() {
  findTriplets({0, -1, 2, -3, 1}, -2);
  findTripletsTwoPinters({0, -1, 2, -3, 1}, -2);

  // test stoi stol stoll
  long long a = (long long )INT32_MAX + 10;
  string b = to_string(a);
  cout<<a<<endl;
  cout << b << endl;
  cout << stol(b) << endl;
}
