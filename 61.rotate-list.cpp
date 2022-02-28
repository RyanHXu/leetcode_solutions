/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */
#include "bits/stdc++.h"

using namespace std;
// @lc code=start
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 1) vector<ListNode*> 
// 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode *> temp;
        while (head)
        {
            temp.push(head);
            head = head->next;
        }
        
    }
};
// @lc code=end

