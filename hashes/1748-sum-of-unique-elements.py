from typing import List

def sumOfUnique(nums: List[int]) -> int:
    unique = {}
    unique_sum = 0
    for n in nums:
        unique[n] = unique.get(n, 0) + 1
        
    for n, count in unique.items():
        if count == 1:
            unique_sum += n
            
    return unique_sum