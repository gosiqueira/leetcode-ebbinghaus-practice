from typing import List

from structures import TreeNode


def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
    if len(preorder) == 0 or len(inorder) == 0: return None
    
    val = preorder.pop(0)
    index_val = inorder.index(val)
    
    
    left, right = None, None
    
    if index_val > 0:
        left = self.buildTree(preorder, inorder[:index_val])
        
    if index_val < len(inorder):
        right = self.buildTree(preorder, inorder[index_val + 1:])
        
    return TreeNode(val, left, right)