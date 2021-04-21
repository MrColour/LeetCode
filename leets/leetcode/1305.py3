# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def traverse(root, bucket):
    if (root is None):
        return

    traverse(root.left, bucket)
    bucket += [root.val]
    traverse(root.right, bucket)

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        collection = []
        traverse(root1, collection)
        traverse(root2, collection)
        collection.sort()
        return (collection)