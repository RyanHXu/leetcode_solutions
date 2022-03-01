/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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

// @lc code=start

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
      if(head==nullptr || head->next==nullptr){
          return head;
      }

      int n = 1;
      ListNode *t = head;
      while (t->next)
      {
          ++n;
          t = t->next;
      }
      t->next = head;
      t = t->next;

      for (int i = 0; i < n-k%n-1; ++i) {
          t = t->next;
      }
      head = t->next;
      t->next = nullptr;

      return head;
  }
};
// @lc code=end

// cornercase n<=1, k==0
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    vector<ListNode *> res;
    ListNode *t = head;
    while (t) {
      res.push_back(t);
      t = t->next;
    }
    int n = res.size();

    if (n <= 1) {
      return head;
    }
    k = k % n;
    if (k == 0) {
      return head;
    }

    res[n - k - 1]->next = nullptr;
    res.back()->next = res.front();

    return res[n - k];
  }
};