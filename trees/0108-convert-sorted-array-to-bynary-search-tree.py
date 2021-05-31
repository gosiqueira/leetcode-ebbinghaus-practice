from typing import List

from structures import TreeNode


def sortedArrayToBST(nums: List[int]) -> TreeNode:
    if len(nums) == 0:
        return None
        
    l, r = 0, len(nums) - 1
    mid = l + (r-l) // 2
    root = TreeNode(nums[mid])
    root.left = sortedArrayToBST(nums[:mid])
    root.right = sortedArrayToBST(nums[mid+1:])
    return root
