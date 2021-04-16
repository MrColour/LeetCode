# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def traverse(root, run_sum, depth):
    if (root is None):
        return 
    if (len(run_sum) <= depth):
        run_sum += [0]
    run_sum[depth] += root.val

    traverse(root.left, run_sum, depth + 1)
    traverse(root.right, run_sum, depth + 1)

class Solution:

#     def traverse(root: TreeNode, run_sum: List[int], depth: int):
#         if (len(run_sum) < depth):
#             run_sum += [0]
#         run_sum[depth] += root.val

#         traverse(root.left, run_sum, depth + 1)
        # traverse(root.right, run_sum, depth + 1)
    
    def deepestLeavesSum(self, root: TreeNode) -> int:
        running_sum = [0]
        traverse(root, running_sum, 0)
        return (running_sum[-1])