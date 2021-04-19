# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def convert(root, sum):
    if (root is None):
        return (0)

    convert(root.right, sum)
    sum[0] += root.val
    root.val = sum[0]
    convert(root.left, sum)


class Solution:

    def bstToGst(self, root: TreeNode) -> TreeNode:

        sum = [0]
        convert(root, sum)
        return (root)
