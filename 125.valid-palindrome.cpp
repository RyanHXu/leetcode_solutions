/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      while (i < j && !isalnum(s[i])) {
        ++i;
      }

      while (i < j && !isalnum(s[j])) {
        --j;
      }

      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
}
