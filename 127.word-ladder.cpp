/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

class SolutionBiBFS {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    // if endWord doesn't exist in wordList, return 0
    if (!dict.count(endWord)) {
      return 0;
    }

    int l = beginWord.size();

    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};

    int step = 0;

    while (!q1.empty() && !q2.empty()) {
      ++step;

      // alwasy expend the smaller queue first
      if (q1.size() > q2.size()) {
        swap(q1, q2);
      }

      unordered_set<string> q;
      // traverse the smaller queue
      for (string w : q1) {
        // traverse the word w
        for (int i = 0; i < l; ++i) {
          char c = w[i];
          // try all the characters and find the possible
          for (int j = 'a'; j <= 'z'; ++j) {
            w[i] = j;
            if (q2.count(w))
              return step + 1;
            if (!dict.count(w))
              continue;
            dict.erase(w);
            q.insert(w);
          }

          w[i] = c;
        }
      }
      swap(q1, q);
    }

    // return 0, if we can't get endWord
    return 0;
  }
};

// @lc code=end


// BFS
class SolutionBFS {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    // if endWord doesn't exist in wordList, return 0
    if (!dict.count(endWord)) {
      return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int step = 0;
    int l = beginWord.size();
    while (!q.empty()) {
      ++step;
      // BFS - traverse all its neighbour
      for (int size = q.size(); size > 0; --size) {
        string w = q.front();
        q.pop();
        // traverse word w
        for (int i = 0; i < l; ++i) {
          char c = w[i];
          // traverse a single character
          for (int j = 'a'; j <= 'z'; ++j) {
            w[i] = j;
            if (w == endWord) {
              return step + 1;
            }
            // if updated w exist in dict, execute the following code to delete it from dict, and insert it into q
            if (!dict.count(w)) {
              continue;
            }
            dict.erase(w);
            q.push(w);
          }
          w[i] = c;
        }
      }
    }

    // return 0, if we can't get endWord
    return 0;
  }
};

// FIXME: , recursion seems doesn't work here
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
  SolutionBFS s;
  vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  cout << s.ladderLength("hit", "cog", wordList) << endl;

  vector<string> wordList2{"aaa", "dot", "dog", "lot", "log", "cog"};
  cout << s.ladderLength("aaa", "aaa", wordList) << endl;
}