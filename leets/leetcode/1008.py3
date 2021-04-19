def traverse(root, order, big, at):
    
    if (at[0] >= len(order)):
        return ;
    
    if (order[at[0]] < root.val):
        root.left = TreeNode(order[at[0]])
        at[0] += 1
        traverse(root.left, order, root.val, at)
        
    if (at[0] >= len(order)):
        return ;
        
    if (order[at[0]] < big):
        root.right = TreeNode(order[at[0]])
        at[0] += 1
        traverse(root.right, order, big, at)
    
    
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        at = [1]
        root = TreeNode(preorder[0])
        traverse(root, preorder, 9223372036854775807, at)
        return (root)