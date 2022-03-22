#include "bits/stdc++.h"

using namespace std;

// brute force idea
// try all three operations and iterate s1 and s2
// 1) if s1[i]==s2[j], we recursively compare the remaining part
// 2) if s1[i]!=s2[j], we call delete, insert, replace opetions recursively
class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {

    return findMinOperations(s1, s2, 0, 0);
  }

  int findMinOperations(const string &s1, const string &s2, int i, int j) {
    if (i == s1.length()) {
      return s2.length() - j;
    }

    if (j == s2.length()) {
      return s1.length() - i;
    }

    int c1 = 0, c2 = 0, c3 = 0;
    if (s1[i] == s2[j]) {
      return findMinOperations(s1, s2, i + 1, j + 1);
    }

    c1 = 1 + findMinOperations(s1, s2, i + 1, j);     // perform deletion
    c2 = 1 + findMinOperations(s1, s2, i, j + 1);     // perform insertion
    c3 = 1 + findMinOperations(s1, s2, i + 1, j + 1); // perform replace

    return min(c1, min(c2, c3));
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}