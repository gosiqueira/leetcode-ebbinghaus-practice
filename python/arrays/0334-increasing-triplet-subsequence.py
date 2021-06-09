from typing import List

def increasingTriplet(nums: List[int]) -> bool:
    i, j = float('inf'), float('inf')
    for n in nums:
        if n <= i: i = n
        elif n <= j: j = n
        else: return True
    return False
