from typing import List


def maxOperations(self, nums: List[int], k: int) -> int:
    max_op = 0
    operations = defaultdict(int)
    
    for num in nums:
        if operations[num] > 0:
            operations[num] -= 1
            max_op += 1
        else:
            operations[k - num] += 1
    
    return max_op