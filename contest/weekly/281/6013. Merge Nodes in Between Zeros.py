# Definition for singly-linked list.
from pprint import pprint
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# TODO: don't make thing complex
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head

        while temp:
            while temp.next.val!= 0:
                temp.val += temp.next.val
                temp.next=temp.next.next
            if temp.next.val == 0:
                temp.next = temp.next.next
                temp = temp.next
        
        return head
            

def createListNode(a: list[int]):
    temp = head = ListNode(0)
    for sub in a:
        temp.next = ListNode(sub)
        temp = temp.next
    return head.next


def traversal(head):
    temp = head
    while temp:
        print(temp.val, end=", ")
        temp = temp.next
    print()


head = createListNode([0, 3, 1, 0, 4, 5, 2, 0])
traversal(head)

s = Solution()
head = s.mergeNodes(head)
traversal(head)
