import math
import numpy
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res=[]
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            res.append(root.val)
            inorder(root.right)
        inorder(root)
        return(res)


root = TreeNode(1)

root.left = TreeNode(2)

root.right = TreeNode(3)
res = Solution()
print(res.minDiffInBST(root))
        