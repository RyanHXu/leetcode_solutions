#include "bits/stdc++.h"

using namespace std;



class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
      
    return -1;
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}