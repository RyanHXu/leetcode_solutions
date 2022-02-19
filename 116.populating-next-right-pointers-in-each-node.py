#
# @lc app=leetcode id=116 lang=python3
#
# [116] Populating Next Right Pointers in Each Node
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from collections import deque
from email.quoprimime import quote
import queue


class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root == None:
            return root

        q = deque([root])

        while q:
            level_size = len(q)
            for i in range(level_size):
                curr = q.popleft()
                if i < level_size-1:
                    curr.next = q[0]

                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)

        return root


# @lc code=end
