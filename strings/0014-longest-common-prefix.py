from typing import List

def longestCommonPrefix(strs: List[str]) -> str:
    subseq = ''
    lengths = [len(s) for s in strs]

    for i in range(min(lengths)):
        if len(set([s[i] for s in strs])) == 1:
            subseq += strs[0][i]
        else:
            break
            
    return subseq
