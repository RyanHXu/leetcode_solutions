#include "bits/stdc++.h"

using namespace std;

int findSum(string str) {
  string temp;
  for (const auto val : str) {
    if (isdigit(val)) {
      temp += val;
    }
  }
  return stoi(temp);
}
// Driver code
int main() {
  string str = "12abc20yz68";

  cout << findSum(str)<<endl;

  return 0;
}
