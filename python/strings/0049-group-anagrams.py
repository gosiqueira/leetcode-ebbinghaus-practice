from typing import List

def groupAnagrams(strs: List[str]) -> List[List[str]]:
    groups = {}
    for s in strs:
        key = ''.join(sorted(s))
        if key not in groups:
            groups[key] = [s]
        else:
            groups[key].append(s)
            
    return [group for group in groups.values()]