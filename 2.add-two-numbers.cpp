/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* head = dummyHead;

    int sum = 0, carry = 0;

    while (l1 || l2) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      sum = x + y + carry;
      carry = sum / 10;

      dummyHead->next = new ListNode(sum % 10);
      dummyHead = dummyHead->next;
    
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }

    if (carry > 0) {
      dummyHead->next = new ListNode(1);
    }

    return head->next;
  }
};

// @lc code=end

class Solution2 {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto t_v1 = extract_nodes_val(l1);
    auto t_v2 = extract_nodes_val(l2);
    ListNode* t_node = l1;
    ListNode* head = t_node;

    vector<int> v1;
    vector<int> v2;

    // make sure v1 is the longer one
    if (t_v1.size() <= t_v2.size()) {
      v1 = move(t_v2);
      v2 = move(t_v1);
      t_node = l2;
      head = l2;
    } else {
      v1 = move(t_v1);
      v2 = move(t_v2);
    }

    int carry = 0;
    int len_v1 = v1.size();
    int len_v2 = v2.size();

    for (int i = 0; i < len_v1; ++i) {
      int t = i > len_v2 - 1 ? 0 : v2[i];
      int sum = v1[i] + t + carry;
      carry = sum / 10;
      t_node->val = sum % 10;
      if (i == len_v1 - 1 && carry > 0) {
        t_node->next = new ListNode(carry);
      } else {
        t_node = t_node->next;
      }
    }

    return head;
  }

  vector<int> extract_nodes_val(ListNode* l) {
    auto t = l;
    vector<int> v;
    while (t) {
      v.push_back(t->val);
      t = t->next;
    }
    return v;
  }
};

int main() {
  vector<int> t_v1{1, 2};
  vector<int> t_v2{10, 2, 3};
  vector<int> v1;
  vector<int> v2;
  if (t_v1.size() < t_v2.size()) {
    v1 = move(t_v1);
    v2 = move(t_v2);
  }

  int carry = 0;

  for (auto& val : v1) {
    cout << val << " ";
  }
  cout << endl;
  for (auto& val : v2) {
    cout << val << " ";
  }
}
