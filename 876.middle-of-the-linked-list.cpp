/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// TODO: slow and fast pointers
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (true) {
    //  the following oder is important
      if (fast == nullptr || fast->next == nullptr) {
        break;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
// @lc code=end
