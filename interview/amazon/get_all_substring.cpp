#include "bits/stdc++.h"

using namespace std;


void solution(string s){
    int n = s.size();
    /**
     *  abc
     *  a, b, c
     *  ab, bc,
     *  
     */
    string temp;
    // i indicates start index
    // j indicates the length of substring could be
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n-i+1; ++j) {
          cout << s.substr(i, j) << endl;
      }
    }
}

int main(){
    solution("abc");
}


/*
a
ab
abc
b
bc
c
*/