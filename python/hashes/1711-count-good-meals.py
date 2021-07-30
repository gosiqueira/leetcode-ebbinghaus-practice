from typing import List


def countPairs(self, deliciousness: List[int]) -> int:
    counter = Counter(deliciousness)
    total = 0
    
    for d in counter:
        for i in range(22):
            t = (1 << i) - d
            if t in counter:
                if t == d:
                    total += (counter[t] - 1) * counter[t]
                else:
                    total += counter[t] * counter[d]
    
    return (total // 2) % (10**9 + 7)