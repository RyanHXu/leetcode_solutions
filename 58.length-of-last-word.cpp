/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    // corner case
    // "   fly me   to   the moon  "
    // count_if accept predicate 
    auto step =
        find_if(s.rbegin(), s.rend(), [](const auto c) { return !isspace(c); }) - s.rbegin();

    auto it = find(s.rbegin()+step, s.rend(), ' ');
    return it - s.rbegin() - step;
  }
};
// @lc code=end


class Solution2 {
 public:
  int lengthOfLastWord(string s) {
    int i;
    for (i = (int)s.size() - 1; i >= 0; --i) {
      if(!isspace(s[i]))
        break;
      if (isspace(s[i]))
        s.pop_back();
    }
    for (; i >= 0; --i) {
      if (isspace(s[i]))
        break;
    }

    return (int)s.size() -1 - i;
  }
};


int main() {
  string s("hello world ryan");
  auto it = find(s.begin(), s.end(), ' ');
  cout << s.substr(0, it - s.begin()) << '\n';

  // find in reverse order
  auto it2 = find(s.rbegin(), s.rend(), ' ');
  int len = it2 - s.rbegin();
  cout << s.substr(s.size() - len) << '\n';

  string s2("   fly me   to   the moon  ");
  auto step =
      find_if(s2.rbegin(), s2.rend(), [](char c)
           { return !isspace(c); }) - s2.rbegin();

  cout << step << '\n';

  Solution solution;
  cout << solution.lengthOfLastWord("hello")<<'\n';
}