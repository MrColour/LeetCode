# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def sum_tree(root, depth, accum):
    if (root is None):
        return

    if (depth == 0):
        accum += [root.val]

    sum_tree(root.left, depth - 1, accum)
    sum_tree(root.right, depth - 1, accum)

def traverse(root: TreeNode, accum: List[int]) -> None:
    if (root is None):
        return

    if (root.val % 2 == 0):
        sum_tree(root, 2, accum)

    traverse(root.left, accum)
    traverse(root.right, accum)


class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        added = [0]
        traverse(root, added)
        return (sum(added))
