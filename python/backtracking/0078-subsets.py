from typing import List


def int2ind(val, items):
    indicator = bin(val)[2:]
    indicator = '0' * (len(items) - len(indicator)) + indicator
    return [items[i] for i in range(len(items)) if indicator[i] == '1']    
    

def subsets(self, nums: List[int]) -> List[List[int]]:
    return [int2ind(val, nums) for val in range(2 ** len(nums))]