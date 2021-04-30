# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def traverse(root, val):
    if (root is None):
        return

    if (root.val < val and root.right is None):
        root.right = TreeNode(val)
        return

    if (root.val > val and root.left is None):
        root.left = TreeNode(val)
        return

    if (root.val < val):
        traverse(root.right, val)
    else:
        traverse(root.left, val)

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if (root is None):
            return (TreeNode(val))

        traverse(root, val)

        return (root)        