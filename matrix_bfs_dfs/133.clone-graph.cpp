/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include "bits/stdc++.h"

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// @lc code=start

// defs
class Solution {
public:
  unordered_map<Node *, Node *> visited;
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return node;
    }

    // node in visited
    if (visited.find(node) != visited.end()) {
      return visited[node];
    }

    Node *cloneNode = new Node(node->val);
    visited[node] = cloneNode;

    for (Node *neighbor : node->neighbors) {
      cloneNode->neighbors.push_back(cloneGraph(neighbor));
    }

    return cloneNode;
  }
};
// @lc code=end
