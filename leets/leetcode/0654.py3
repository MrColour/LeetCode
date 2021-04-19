# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def max_tree(nums):
    if (len(nums) < 1):
        return None
    big = max(nums)
    res = TreeNode(big)

    res.left = max_tree(nums[0:nums.index(big)])
    res.right = max_tree(nums[nums.index(big) + 1:])
    
    return (res)

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        return (max_tree(nums))

