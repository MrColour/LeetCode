# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

def traverse(root, nums, at):
    if (root is None):
        return
    
    traverse(root.left, nums, at)
    root.val = nums[at[0]]
    at[0] += 1
    traverse(root.right, nums, at)

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        gather = []

        order = deque()
        order.append(root)
        while (order):

            elem = order.pop()

            if (elem is not None):
                gather += [elem.val]
                order.append(elem.left)
                order.append(elem.right)
        print(gather)
        
        new = deque()
        start = TreeNode(0)
        new.append(start)
        i = 1
        while (i < len(gather)):
            base = new.popleft()
            
            base.left = TreeNode(i)
            new.append(base.left)
            i += 1
            if (i < len(gather)):
                base.right = TreeNode(i)
                new.append(base.right)
                i += 1
                
        at = [0]
        gather.sort()
        traverse(start, gather, at)
            
        return (start)