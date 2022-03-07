/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/discuss/1499005/C%2B%2B-or-Sliding-window-or-with-explanation

// @lc code=start
// the key idea is we need two seprate sliding windows,
class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int left = 0, right, cnt = 0, res = 0;
    int n = answerKey.size();
    for (right = 0; right < n; ++right) {
      if (answerKey[right] == 'F')
        ++cnt;
      // NOTE: using if and while are pretty different
      // never reduce windows side,
      if (cnt > k) {
        if (answerKey[left] == 'F') {
          --cnt;
        }
        ++left;
      }
    }
    res = max(res, right - left);

    left = 0, cnt = 0;
    for (right = 0; right < n; ++right) {
      if (answerKey[right] == 'T')
        ++cnt;
      if (cnt > k) {
        if (answerKey[left] == 'T') {
          --cnt;
        }
        ++left;
      }
    }
    res = max(res, right - left);

    return res;
  }
};

// @lc code=end

int main() {
  Solution s;
  cout << s.maxConsecutiveAnswers("TTFTTTTTFT", 1) << endl;
}