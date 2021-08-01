from typing import List


def isPossible(self, nums: List[int]) -> bool:
    seq = defaultdict(list)
    for num in nums:
        i = 0
        if num - 1 in seq:
            i = heapq.heappop(seq[num-1])
            
            if len(seq[num-1]) == 0:
                del seq[num-1]
        heapq.heappush(seq[num], i + 1)
        
    return all(heapq.heappop(seq[x]) >= 3 for x in seq)