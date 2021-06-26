from collections import deque
from typing import List

from structures import TreeNode


def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
    if root is None: return []

    queue, response = deque([root]), []

    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)

        response.append(level)

    for i in range(len(response)):
        if i % 2 == 1:
            response[i].reverse()

    return response