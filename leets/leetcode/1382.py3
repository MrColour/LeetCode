# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        gather = []

        order = deque(TreeNode)
        order.append(root)
        while (order):

            elem = order.pop()

            if (elem is not None):
                gather += elem.val
                order.append(elem.left)
                order.append(elem.right)
        print(gather)
        return ([])

