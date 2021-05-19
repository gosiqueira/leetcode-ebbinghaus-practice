from typing import List

def moveZeroes(nums: List[int]) -> None:
    i = 0
    num_zeroes = 1
    while i < len(nums) and num_zeroes < len(nums):
        if nums[i] == 0:
            num_zeroes += 1
            for j in range(i+1, len(nums)):
                nums[j-1] = nums[j]
            nums[len(nums)-1] = -1
        else:
            i += 1
            
    for i in range(1, num_zeroes):
        nums[-i] = 0