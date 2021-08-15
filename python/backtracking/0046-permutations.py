from typing import List


def permute(self, nums: List[int]) -> List[List[int]]:
    return [[n] + p
            for i, n in enumerate(nums)
            for p in self.permute(nums[:i] + nums[i+1:])] or [[]]