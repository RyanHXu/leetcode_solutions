#include "bits/stdc++.h"

using namespace std;

//  int c1 = longest common subsequence
// n1 -c1 + n2 -c1 + c1

class SCS {

public:
  int findSCSLength(const string &s1, const string &s2) {

    return findSCSLengthRecursion(s1, s2, 0, 0);
    return -1;
  }
  int findSCSLengthRecursion(const string &s1, const string &s2, int i1,
                             int i2) {

    if (i1 == s1.size()) {
      return s2.length() - i2;
    }
    if (i2 == s2.size()) {
      return s1.length() - i1;
    }
    if (s1[i1] == s2[i2])
      return 1 + findSCSLengthRecursion(s1, s2, i1 + 1, i2 + 1);

    int c1 = 1 + findSCSLengthRecursion(s1, s2, i1 + 1, i2);
    int c2 = 1 + findSCSLengthRecursion(s1, s2, i1, i2 + 1);
    return min(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  SCS *scs = new SCS();
  cout << scs->findSCSLength("abcf", "bdcf") << endl;
  cout << scs->findSCSLength("dynamic", "programming") << endl;

  delete scs;
}