/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

#include "bits/stdc++.h"

using namespace std;

// Tries + DFS has two approaches to build

// map
// https://leetcode.com/problems/search-suggestions-system/discuss/718659/C%2B%2B-Trie-and-Binary-search-solution.-Detailed-Explanation

// char[26]
// https://leetcode.com/problems/search-suggestions-system/solution/

// TODO: three approaches
// Trie + DFS
// binary search - lower_bound
// brute force - leaner scan

// @lc code=start

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    vector<vector<string>> res;
    sort(products.begin(), products.end());
    int start = 0, bStart = 0, n = products.size();
    string prefix;
    for (const auto &c : searchWord) {
      prefix += c;
      start = lower_bound(products.begin(), products.end(), prefix) -
              products.begin();

      res.push_back({});

      for (int i = start; i < min(start + 3, n) &&
                          !products[i].compare(0, prefix.length(), prefix);
           ++i) {
        res.back().push_back(products[i]);
      }
      bStart = start;
    }
    return res;
  }
};
// @lc code=end

class Solution_1 {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    vector<vector<string>> res;
    int n = searchWord.size();
    sort(products.begin(), products.end());
    int bstart = 0;
    for (int i = 0; i < n; ++i) {
      vector<string> temp;
      string keyWord = searchWord.substr(0, i + 1);
      auto it = lower_bound(products.begin() + bstart, products.end(), keyWord);

      for (int j = 0; j < 3; ++j) {
        if (it == products.end() || (*it).substr(0, i + 1) != keyWord) {
          break;
        }
        temp.push_back(*it);
        ++it;
      }

      res.push_back(temp);
    }
    return res;
  }
};

// TODO:  Tires + DFS
// TODO: lower_bound using binary search
class Trie {
  struct Node {
    bool isWord = false;
    // item children contains 26 chars
    vector<Node *> children{vector<Node *>(26, nullptr)};
  } * root, *curr;

  void dfsWithPrefix(Node *curr, string &word, vector<string> &result) {
    if (result.size() == 3) {
      return;
    }
    if (curr->isWord) {
      result.push_back(word);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (curr->children[c - 'a']) {
        word += c;
        dfsWithPrefix(curr->children[c - 'a'], word, result);
        word.pop_back();
      }
    }
  }

public:
  Trie() { root = new Node; }

  // build Trie tree
  void insert(string &s) {
    // transversal from root
    curr = root;
    for (auto &c : s) {
      if (!curr->children[c - 'a'])
        curr->children[c - 'a'] = new Node();
      curr = curr->children[c - 'a'];
    }

    curr->isWord = true;
  }

  vector<string> getWordsStartingWith(string &prefix) {
    curr = root;
    vector<string> res;

    for (auto &c : prefix) {
      if (!curr->children[c - 'a'])
        return res;
      curr = curr->children[c - 'a'];
    }
    dfsWithPrefix(curr, prefix, res);
    return res;
  }
};

class Solution2 {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    Trie trie = Trie();
    vector<vector<string>> res;
    for (auto &w : products) {
      trie.insert(w);
    }
    string prefix;
    for (auto &val : searchWord) {
      prefix += val;
      res.push_back(trie.getWordsStartingWith(prefix));
    }
    return res;
  }
};

// TODO: accepted -  brute force
class Solution3 {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    vector<vector<string>> res;
    int n = searchWord.size();
    sort(products.begin(), products.end());

    for (int i = 0; i < n; ++i) {
      vector<string> temp;
      string keyWord = searchWord.substr(0, i + 1);
      auto it = find_if(products.begin(), products.end(), [&](const auto &a) {
        if (a.substr(0, i + 1) == keyWord) {
          return true;
        }
        return false;
      });

      for (int j = 0; j < 3; ++j) {
        if (it == products.end() || (*it).substr(0, i + 1) != keyWord) {
          break;
        }
        temp.push_back(*it);
        ++it;
      }

      res.push_back(temp);
    }
    return res;
  }
};

int main() {
  // test find_if
  vector<int> ivec{1, 2, 3, 4, 5, 6};
  cout << *find_if(ivec.begin(), ivec.end(), [](const auto &a) {
    return a > 3;
  }) << endl;

  cout << endl;

  Solution s;
  // test 1

  vector<string> svec1{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
  string parm1("mouse");

  for (const auto &it : s.suggestedProducts(svec1, parm1)) {
    for (const auto &val : it) {
      cout << val << ' ';
    }
    cout << endl;
  }
  cout << endl;

  // test 2

  vector<string> svec2{"bags", "baggage", "banner", "box", "cloths"};
  string parm2("bags");

  for (const auto &it : s.suggestedProducts(svec2, parm2)) {
    for (const auto &val : it) {
      cout << val << ' ';
    }
    cout << endl;
  }
  cout << endl;

  // TODO: test lower_bound
  vector<int> nums = {1, 2, 3, 3, 4, 4, 4, 5};
  cout << lower_bound(nums.begin(), nums.end(), 3) - nums.begin() << endl;
  cout << upper_bound(nums.begin(), nums.end(), 3) - nums.begin() << endl;
}