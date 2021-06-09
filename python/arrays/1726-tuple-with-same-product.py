from typing import List

def tupleSameProduct(nums: List[int]) -> int:
    distinct = 0
    prods = {}
    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] != nums[j]:
                prod = nums[i]*nums[j]
                prods[prod] = prods.get(prod, 0) + 1

    print(prods)

    for idx in prods:
        distinct += prods[idx] * (prods[idx] - 1) // 2

    return distinct * 8