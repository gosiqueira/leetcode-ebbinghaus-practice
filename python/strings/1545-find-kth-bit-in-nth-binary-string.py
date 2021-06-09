def findKthBit(n: int, k: int) -> str:
    return genSequence(n)[k-1]
    
def genSequence(n):    
    def invert(seq):
        return ''.join(['0' if s == '1' else '1' for s in seq])
    
    def reverse(seq):
        return seq[::-1]
    
    if n == 1:
        return '0'
    
    prev = genSequence(n-1)
    return prev + '1' + reverse(invert(prev))