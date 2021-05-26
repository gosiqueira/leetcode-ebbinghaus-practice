from typing import List

def threeSum(nums: List[int]) -> List[List[int]]:
    response = []
    nums.sort()
    
    for i, n in enumerate(nums):
        if i > 0 and n == nums[i - 1]:
            continue
            
        l, r = i + 1, len(nums) - 1
        while l < r:
            s = n + nums[l] + nums[r]
            if s >  0:
                r -= 1
            elif s < 0:
                l += 1
            else:
                response.append([n, nums[l], nums[r]])
                
                l += 1
                while nums[l] == nums[l - 1] and l < r:
                    l += 1
    
    return response