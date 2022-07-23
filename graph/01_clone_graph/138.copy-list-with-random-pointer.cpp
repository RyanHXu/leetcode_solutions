/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include "bits/stdc++.h"

using namespace std;

// NOTE: 
// https://leetcode.com/problems/copy-list-with-random-pointer/solution/
// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
// @lc code=start

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;
    map<Node*, Node*> m;
    int i = 0;
    Node* ptr = head;
    while (ptr) {
      m[ptr] = new Node(ptr->val);
      ptr = ptr->next;
    }
    ptr = head;
    while (ptr) {
      m[ptr]->next = m[ptr->next];
      m[ptr]->random = m[ptr->random];
      ptr = ptr->next;
    }
    return m[head];
  }
};
// @lc code=end

class Solution2 {
 public:
  unordered_map<Node*, Node*> visited;
  Node* copyRandomList(Node* head) {
    if (!head) return head;

    Node* node = new Node(head->val);

    visited[head] = node;

    node->next = copyRandomList(head->next);
    node->random = visited[head->random];

    return node;
  }
};