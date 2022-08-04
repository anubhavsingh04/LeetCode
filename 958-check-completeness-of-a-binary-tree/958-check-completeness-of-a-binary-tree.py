from queue import Queue
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q=Queue()
        q.put(root)
        found=0
        while not q.empty():
            k=q.get()
            if k==None:
                found=1
            else:
                if found:
                    return False
                else:
                    q.put(k.left)
                    q.put(k.right)
        return True
        