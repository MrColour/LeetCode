# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def    traverse(root: TreeNode, val: int, accum: List[int]):

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        added = [0]
        if (root.val % 2 == 0):
            traverse(root, 2, added)
        else:
            traverse(root, 0, added)
        return sum(added)