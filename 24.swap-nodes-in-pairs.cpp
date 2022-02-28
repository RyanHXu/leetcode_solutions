/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

#include "bits/stdc++.h"

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for singly-linked list.

// three approach for this kind of problem
// 1): extract value
// 2): create vector and store each node's address
// 3): swap
// NOTE: pointer & linked list
// @lc code=start
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead;
    ListNode *t = head;
    ListNode *next;
    while (t && t->next) {
      next = t->next->next;

      prev->next = t->next;
      prev->next->next = t;
      prev->next->next->next = next;

      prev = prev->next->next;
      t = next;
    }
    if(t){
        prev->next = t;
    }

    return dummyHead->next;
  }
};

// @lc code=end

class Solution2 {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *t = head;
    vector<ListNode *> lvec;
    while (t) {
      lvec.push_back(t);
      t = t->next;
    }
    if (lvec.size() >= 2) {
      int i = 0;
      while (i + 1 < lvec.size()) {
        swap(lvec[i], lvec[i + 1]);
        i += 2;
      }
    }

    for (int i = 1; i < lvec.size(); ++i) {
      lvec[i - 1]->next = lvec[i];
    }
    lvec.back()->next = nullptr;
    return lvec[0];
  }
};

// FIXME: consider corner case
class Solution3 {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *pHead = new ListNode(0);
    pHead->next = head;
    vector<int> extractd_value;
    while (head) {
      extractd_value.push_back(head->val);
      head = head->next;
    }

    int i = 0;
    while (i < extractd_value.size()) {
      swap(extractd_value[i], extractd_value[i + 1]);
      i += 2;
    }
    head = pHead;
    for (const auto val : extractd_value) {
      pHead->next = new ListNode(val);
      pHead = pHead->next;
    }
    return head->next;
  }
};
