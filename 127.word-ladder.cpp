/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return 0;
    queue<string> q;
    q.push(beginWord);
    int step = 0;
    int l = beginWord.length();
    while (!q.empty()) {
      ++step;
      for (int size = q.size(); size > 0; --size) {
        string w = q.front();
        q.pop();
        for (int i = 0; i < l; ++i) {
          char c = w[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            w[i] = j;
            if (w == endWord)
              return step + 1;
            if (!dict.count(w))
              continue;
            dict.erase(w);
            q.push(w);
          }
          w[i] = c;
        }
      }
    }
    return 0;
  }
};
// @lc code=end



// FIXME, recursion seems doesn't work here
// bfs+backtrack
class Solution3 {
  unordered_map<string, int> m;
  int count = 0;
  int n;

public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    for (const auto &val : wordList) {
      ++m[val];
    }
    n = wordList.size();
    m[beginWord] = 0;
    bfs(beginWord, endWord, wordList);
    return count;
  }
  void bfs(string beginWord, string endWord, vector<string> &wordList) {
    for (int i = 0; i < beginWord.length(); ++i) {
      string key = beginWord;

      for (int j = 0; j < 26; ++j) {
        key[i] = (char)('a' + j);
        if (key == endWord) {
          return;
        }
        if (count > n) {
          break;
        }
        if (m.find(key) != m.end() && m[key] > 0) {
          ++count;
          m[key] = 0;
          bfs(key, endWord, wordList);
          m[key] = 1;
          --count;
        }
      }
    }
  }
};
int main() {
  vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  Solution s;
  cout << s.ladderLength("hit", "cog", wordList) << endl;
}