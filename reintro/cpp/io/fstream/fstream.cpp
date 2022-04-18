#include "bits/stdc++.h"

using namespace std;

int main() {
  fstream file;
  file.open("1.txt", ifstream::in);
  char c = file.get();
  while (file.good()) {
    cout << c;
    c = file.get();
  }
  
  cout << endl;
  file.close();
}