#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int *p = new int(65);
  char *ch = reinterpret_cast<char *>(p);
  cout << *p << endl;
  cout << *ch << endl;
  cout << p << endl;
  cout << ch << endl;
  cout << "👋👋👋" << endl;
  int a = 10;
  int b = 20;
  string s;
  s.append(reinterpret_cast<const char *>(&a), sizeof(a));

  s.append(reinterpret_cast<const char *>(&b), sizeof(b));

  cout << s.length() << endl;
  cout << *reinterpret_cast<int *>(s.data()) << endl;
  cout << *reinterpret_cast<int *>(s.data()+4) << endl;

  return 0;
}
