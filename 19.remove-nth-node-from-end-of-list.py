#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# TODO: two pointers, slow and fast pointers
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        first = second = dummy
        # n+1 because first and second jump from dumm
        for i in range(n+1):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next
        
# @lc code=end




#%%

# two pass
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # remove L - nth +1
        length = 0
        p = temp = head
        while p:
            p = p.next
            length += 1

        if length == n:
            return head.next

        for i in range(length-n-1):
            temp = temp.next
        temp.next = temp.next.next

        return head
