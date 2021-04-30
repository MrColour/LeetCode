# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def create(root, val):
    if (root is None):
        return

    root.val = val

    create(root.left, root.val * 2 + 1)
    create(root.right, root.val * 2 + 2)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def create(root, val):
    if (root is None):
        return

    root.val = val

    create(root.left, root.val * 2 + 1)
    create(root.right, root.val * 2 + 2)

def traverse(root, seek, dest):
    if (root is None or dest[0] is not None):
        return

    if (root.val is seek):
        dest[0] = root
        return

    traverse(root.left, seek, dest)
    traverse(root.right, seek, dest)


class FindElements:

    def __init__(self, root: TreeNode):
        create(root, 0)
        self.root = root
        

    def find(self, target: int) -> bool:
        dest = [None]

        traverse(self.root, target, dest)

        if (dest[0] is None):
            return (False)
        else:
            return (True)


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)