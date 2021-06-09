from typing import List

def findKthPositive(arr: List[int], k: int) -> int:
    numbers = {}
    for num in arr:
        numbers[num] = True
        
    cur = 0
    missing = 0
    for i in range(1, list(numbers.keys())[-1] + 1):
        if cur == k:
            break
            
        if i not in numbers:
            cur += 1
        
        missing = i
            
    while cur != k:
        missing += 1
        cur += 1
        
    return missing