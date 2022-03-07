/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// bfs+backtrack
class Solution {
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
        key[i] = (char)('a' +j);
        if(key == endWord){
            return;
        }
        if(count>n){
            break;
        }
        if (m.find(key) != m.end() && m[key]>0) {
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
// @lc code=end
int main() {
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    Solution s;
    cout<<s.ladderLength("hit", "cog", wordList);
}