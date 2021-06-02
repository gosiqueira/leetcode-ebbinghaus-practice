def longestPalindrome(s: str) -> str:
    n = len(s)
    res = s[0]
    for i in range(n):
        # Check once for even palindrome size
        mid = i
        left = i - 1
        while mid < n and left >= 0 and s[mid] == s[left]:
            left -= 1
            mid  += 1
        res = max(res, s[left+1:mid], key=lambda x: len(x))
        
        # Check twice for odd palindrome size
        left  = i - 1
        right = i + 1
        while left >= 0 and right < n and s[left] == s[right]:
            left  -= 1
            right += 1
        res = max(res, s[left+1:right], key=lambda x: len(x))
        
    return res