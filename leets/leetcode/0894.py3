# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict
from collections import deque

class Solution:
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        nodes = defaultdict(list)

        nodes[1] = [TreeNode(0)]
        if (n % 2 == 0):
            return ([])
        if (n < 2):
            return (nodes[1])
        for i in range(1, n + 1, 2):
            # print(i)
            for j in range(1, i, 2):

                # print("Using: ", j)

                for left in nodes[j]:
                    # print("Mixing with: ", i - j - 1)
                    for right in nodes[i - j - 1]:
                        new = TreeNode(0)
                        new.left = left
                        new.right = right
                        nodes[i] += [new]    
                        
        return (nodes[i])