# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def traverse(root1, root2):
    if (root2 is None):
        return

    root1.val += root2.val

    if (root1.left is None):
        root1.left = root2.left
    else:
        traverse(root1.left, root2.left)

    if (root1.right is None):
        root1.right = root2.right
    else:
        traverse(root1.right, root2.right)

class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if (root1 is None):
            return (root2)
        traverse(root1, root2)

        return (root1)
        