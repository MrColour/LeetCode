# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def traverse(root, gather):
    if (root is None):
        return
    
    traverse(root.left, gather)
    gather += [root.val]
    traverse(root.right, gather)

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        gather = []
        traverse(root, gather)

        root = TreeNode(gather[0])
        prev = root
        for num in gather[1:]:
            prev.right = TreeNode(num)
            prev = prev.right
            
        return (root)