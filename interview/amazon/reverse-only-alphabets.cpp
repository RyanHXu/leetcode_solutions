#include "bits/stdc++.h"

using namespace std;

void reverse(string &str) {
  int l = 0, r = str.length() - 1;
  while (l < r) {
    if (!isalpha(str[l]))
      ++l;
    if (!isalpha(str[r]))
      --r;
    if (isalpha(str[l]) && isalpha(str[r]))
      swap(str[l++], str[r--]);
  }
}

int main() {
  string str("AB$C^%DEF*");
  reverse(str);
  cout << str << endl;
//   isupper();
//   toupper();
}