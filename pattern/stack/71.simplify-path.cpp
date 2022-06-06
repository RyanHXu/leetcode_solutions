/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

#include "bits/stdc++.h"

using namespace std;
// TODO:
// https://leetcode.com/problems/simplify-path/discuss/1050697/C%2B%2B-Simple-and-Easy-Solution-Faster-than-94

// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> ivec;
    string res, temp;
    stringstream p(path);

    while (getline(p, temp, '/')) {
        // ignore multiple consecutive slashes and single period
      if (temp == "" or temp == ".") continue;
      if (!ivec.empty() && temp == "..")
        ivec.pop_back();
      else if (temp != "..")
        ivec.push_back(temp);
    }

    for (auto s : ivec) res += "/" + s;

    return ivec.empty() ? "/" : res;
  }
};
// @lc code=end

vector<int> printAllindex(string s1, string s2) {
  vector<int> ivec;
  int start = 0;
  while (start < s1.size()) {
    start = s1.find(s2, start);
    ivec.push_back(start++);
  }

  return ivec;
}

vector<string> split(string s1, string delimiter) {
  vector<string> res;
  int pos = 0;
  while ((pos = s1.find(delimiter)) != string::npos) {
    string token = s1.substr(0, pos);
    res.push_back(token);
    s1.erase(0, pos + delimiter.length());
  }

  return res;
}

vector<string> split2(string s1, string delimiter) {
  vector<string> res;
  int pos = 0;
  string temp;
  stringstream p(s1);

  while (getline(p, temp, delimiter.c_str()[0])) {
    // res.push_back(temp);
    cout << temp << endl;
  }

  return res;
}

int main() {
  string s("X/home/ryan/test/");
  for (const auto& val : printAllindex(s, "/")) {
    cout << val << endl;
  }

  cout << s.substr(0, 5) << endl;
  cout << s << endl;

  // ++i vs i++
  int a = 0;
  int b = a++;
  cout << a << endl;
  cout << b << endl;

  cout << "=======> start" << endl;
  Solution s1;
  s1.simplifyPath(s);
  cout << "=======> start" << endl;
  split2(s, "/");
}
